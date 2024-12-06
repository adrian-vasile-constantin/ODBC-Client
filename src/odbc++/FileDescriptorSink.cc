module;

#include "ODBCXX_Export.h"

#include "intellisense/odbcxx_project_headers.hh"

export module odbc.FileDescriptorSink;

#if !defined MSVC_INTELLISENSE
import std;
import external.boost.iostreams;
import odbc.FileDescriptorDevice;
#endif

namespace odbc
{
    export class ODBCXX_EXPORT FileDescriptorSink: public FileDescriptorDevice
    {
    public:
	struct category: ext::boost::iostreams::closable_tag, ext::boost::iostreams::output_seekable, ext::boost::iostreams::device_tag
	{
	};

	FileDescriptorSink() = default;
	FileDescriptorSink(HandleType handle, Flags flags);
	FileDescriptorSink(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(std::string const &path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(char const *path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::out);

	void open(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(std::string const &path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(char const *path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());

	using FileDescriptorDevice::write;
	using FileDescriptorDevice::seek;
    };
}

inline odbc::FileDescriptorSink::FileDescriptorSink(HandleType handle, Flags flags)
    : FileDescriptorDevice(handle, flags)
{
}

inline odbc::FileDescriptorSink::FileDescriptorSink(std::filesystem::path const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::out)
{
}

inline odbc::FileDescriptorSink::FileDescriptorSink(std::string const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::out)
{
}

inline odbc::FileDescriptorSink::FileDescriptorSink(char const *path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::out)
{
}

inline odbc::FileDescriptorSink::FileDescriptorSink(wchar_t const *path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::out)
{
}

inline void odbc::FileDescriptorSink::open(std::filesystem::path const &path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    FileDescriptorDevice::open(path, mode | std::ios_base::out, dwShareMode);
}

inline void odbc::FileDescriptorSink::open(std::string const &path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    FileDescriptorDevice::open(path, mode | std::ios_base::out, dwShareMode);
}

inline void odbc::FileDescriptorSink::open(char const *path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    FileDescriptorDevice::open(path, mode | std::ios_base::out, dwShareMode);
}

inline void odbc::FileDescriptorSink::open(wchar_t const *path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    FileDescriptorDevice::open(path, mode | std::ios_base::out, dwShareMode);
}
