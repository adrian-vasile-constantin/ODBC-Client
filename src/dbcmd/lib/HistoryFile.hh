#if !defined ODBC_CMD_LIB_HISTORY_FILE_HH
#define ODBC_CMD_LIB_HISTORY_FILE_HH

#include <limits>
#include <memory>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/filter/newline.hpp>
#include <ranges>
#include <filesystem>

#include "HistoryList.hh"

namespace cmd
{
    class HistoryFile
    {
    protected:
	using path = std::filesystem::path;
	using pos_type = std::iostream::pos_type;
	using Container = std::list<std::string>;
	using Index = std::vector<std::pair<pos_type, Container::const_iterator>>;
	
	template <typename CharT>
	    using basic_file = boost::iostreams::basic_file<CharT>;

	template
	<
	    typename DeviceT,
	    typename TraitsT = boost::iostreams::stream_buffer<DeviceT>::traits_type
	>
	    using stream_buffer = boost::iostreams::stream_buffer<DeviceT, TraitsT>;

	static const auto OUT_OF_RANGE_COUNT = (std::numeric_limits<unsigned>::max)();
	unsigned listCapacity = 1024u;
	unsigned cleanEntriesCount = OUT_OF_RANGE_COUNT;

	stream_buffer<basic_file<char>> file_stream_buffer;
	std::iostream localFile { &file_stream_buffer };
	std::iostream &historyFile;

	static auto defaultTruncate(std::streambuf *stream_buf) -> void;
	void (*truncate_func)(std::streambuf *stream_buf);

	Container lines;
	Index lineIndex;

	auto isDirty() const -> bool;

    public:
	HistoryFile(path const &file_path);
	HistoryFile(std::streambuf *stream_buf, void (*truncate_fn)(std::streambuf *stream_buf) = defaultTruncate);
	HistoryFile(std::iostream &file, void (*truncate_fn)(std::streambuf *stream_buf) = defaultTruncate);

	auto clear() -> void;
	auto save() -> void;
	auto reload() -> void;
	auto capacity(unsigned newCapacity) -> unsigned;
	auto capacity() const -> unsigned;
	auto size() const -> unsigned;
	auto getLine(unsigned index) const -> std::string const &;
	auto appendLine(std::string_view line) -> void;
	auto appendLine(unsigned previousIndex) -> void;
	auto removeLine(unsigned index) -> void;
    };
}

inline cmd::HistoryFile::HistoryFile(std::iostream &file, void (*truncate_fn)(std::streambuf *stream_buf)):
    historyFile(file), truncate_func(truncate_fn)
{
    file.exceptions(file.exceptions() | file.badbit);
    reload();
}

inline cmd::HistoryFile::HistoryFile(std::streambuf *stream_buf, void (*truncate_fn)(std::streambuf *stream_buf)):
    localFile { stream_buf }, historyFile { localFile }, truncate_func(truncate_fn)
{
    localFile.exceptions(localFile.exceptions() | localFile.badbit);
    reload();
}

inline auto cmd::HistoryFile::isDirty() const -> bool
{
    return cleanEntriesCount != OUT_OF_RANGE_COUNT;
}

inline auto cmd::HistoryFile::capacity(unsigned newCapacity) -> unsigned
{
    return std::exchange(listCapacity, newCapacity);
}

inline auto cmd::HistoryFile::capacity() const -> unsigned
{
    return listCapacity;
}

inline auto cmd::HistoryFile::size() const -> unsigned
{
    return static_cast<unsigned>(lines.size());
}

inline auto cmd::HistoryFile::getLine(unsigned lineNumber) const -> std::string const &
{
    return *lineIndex[lineNumber - 1u].second;
}

#endif	    // !defined ODBC_CMD_LIB_HISTORY_FILE_HH
