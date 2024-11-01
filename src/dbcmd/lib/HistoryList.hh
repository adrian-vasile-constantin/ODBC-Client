#if !defined ODBC_CMD_LIB_HISTORY_LIST_HH
#define ODBC_CMD_LIB_HISTORY_LIST_HH

#include <limits>
#include <memory>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file.hpp>
#include <ranges>
#include <filesystem>

namespace cmd
{
    class HistoryList
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

	static void defaultTruncate(std::streambuf *stream_buf);
	void (*truncate_func)(std::streambuf *stream_buf);

	Container lines;
	Index lineIndex;

	auto isDirty() const -> bool;

    public:
	HistoryList(path const &file_path);
	HistoryList(std::streambuf *stream_buf, void (*truncate_fn)(std::streambuf *stream_buf) = defaultTruncate);
	HistoryList(std::iostream &file, void (*truncate_fn)(std::streambuf *stream_buf) = defaultTruncate);

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

	using const_iterator = Container::const_iterator;
	using const_reverse_iterator = Container::const_reverse_iterator;

	auto begin() const -> const_iterator;
	auto cbegin() const -> const_iterator;
	auto rbegin() const -> const_reverse_iterator;
	auto crbegin() const -> const_reverse_iterator;

	auto end() const -> const_iterator;
	auto cend() const -> const_iterator;
	auto rend() const -> const_reverse_iterator;
	auto crend() const -> const_reverse_iterator;
    };
}

inline cmd::HistoryList::HistoryList(std::iostream &file, void (*truncate_fn)(std::streambuf *stream_buf)):
    historyFile(file), truncate_func(truncate_fn)
{
    file.exceptions(file.exceptions() | file.badbit);
    reload();
}

inline cmd::HistoryList::HistoryList(std::streambuf *stream_buf, void (*truncate_fn)(std::streambuf *stream_buf)):
    localFile { stream_buf }, historyFile { localFile }, truncate_func(truncate_fn)
{
    localFile.exceptions(localFile.exceptions() | localFile.badbit);
    reload();
}

inline auto cmd::HistoryList::isDirty() const -> bool
{
    return cleanEntriesCount != OUT_OF_RANGE_COUNT;
}

inline auto cmd::HistoryList::capacity(unsigned newCapacity) -> unsigned
{
    return std::exchange(listCapacity, newCapacity);
}

inline auto cmd::HistoryList::capacity() const -> unsigned
{
    return listCapacity;
}

inline auto cmd::HistoryList::size() const -> unsigned
{
    return static_cast<unsigned>(lines.size());
}

inline auto cmd::HistoryList::getLine(unsigned lineNumber) const -> std::string const &
{
    return *lineIndex[lineNumber - 1u].second;
}

inline auto cmd::HistoryList::begin() const -> const_iterator
{
    return lines.begin();
}

inline auto cmd::HistoryList::cbegin() const -> const_iterator
{
    return lines.cbegin();
}

inline auto cmd::HistoryList::rbegin() const -> const_reverse_iterator
{
    return lines.rbegin();
}

inline auto cmd::HistoryList::crbegin() const -> const_reverse_iterator
{
    return lines.crbegin();
}

inline auto cmd::HistoryList::end() const -> const_iterator
{
    return lines.end();
}

inline auto cmd::HistoryList::cend() const -> const_iterator
{
    return lines.cend();
}

inline auto cmd::HistoryList::rend() const -> const_reverse_iterator
{
    return lines.rend();
}

inline auto cmd::HistoryList::crend() const -> const_reverse_iterator
{
    return lines.crend();
}

#endif	    // !defined ODBC_CMD_LIB_HISTORY_LIST_HH
