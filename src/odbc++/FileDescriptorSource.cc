module;

#include "ODBCXX_Export.h"

#include "intellisense/odbcxx_project_headers.hh"

export module odbc.FileDescriptorSource;

#if !defined MSVC_INTELLISENSE
import std;
import external.boost.iostreams;
import odbc.FileDescriptorDevice;
#endif

namespace odbc
{
    export class ODBCXX_EXPORT FileDescriptorSource: public FileDescriptorDevice
    {
    public:
	struct category: ext::boost::iostreams::closable_tag, ext::boost::iostreams::input_seekable, ext::boost::iostreams::device_tag
	{
	};

	FileDescriptorSource() = default;
	FileDescriptorSource(HandleType handle, Flags flags);
	FileDescriptorSource(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(std::string const &path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(char const *path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::in);

	auto open(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)()) -> void;
	auto open(std::string const &path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)()) -> void;
	auto open(char const *path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)()) -> void;
	auto open(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)()) -> void;

	using FileDescriptorDevice::read;
	using FileDescriptorDevice::seek;
    };
}

inline odbc::FileDescriptorSource::FileDescriptorSource(HandleType handle, Flags flags)
    : FileDescriptorDevice(handle, flags)
{
}

inline odbc::FileDescriptorSource::FileDescriptorSource(std::filesystem::path const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::in)
{
}

inline odbc::FileDescriptorSource::FileDescriptorSource(std::string const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::in)
{
}

inline odbc::FileDescriptorSource::FileDescriptorSource(char const *path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::in)
{
}

inline odbc::FileDescriptorSource::FileDescriptorSource(wchar_t const *path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path, mode | std::ios_base::in)
{
}

inline auto odbc::FileDescriptorSource::open(std::filesystem::path const &path, std::ios_base::openmode mode, DWORD dwShareMode) -> void
{
    FileDescriptorDevice::open(path, mode | std::ios_base::in, dwShareMode);
}

inline auto odbc::FileDescriptorSource::open(std::string const &path, std::ios_base::openmode mode, DWORD dwShareMode) -> void
{
    FileDescriptorDevice::open(path, mode | std::ios_base::in, dwShareMode);
}

inline auto odbc::FileDescriptorSource::open(char const *path, std::ios_base::openmode mode, DWORD dwShareMode) -> void
{
    FileDescriptorDevice::open(path, mode | std::ios_base::in, dwShareMode);
}

inline auto odbc::FileDescriptorSource::open(wchar_t const *path, std::ios_base::openmode mode, DWORD dwShareMode) -> void
{
    FileDescriptorDevice::open(path, mode | std::ios_base::in, dwShareMode);
}
