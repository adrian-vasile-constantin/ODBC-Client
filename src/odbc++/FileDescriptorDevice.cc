module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#if defined WINDOWS
# include <windef.h>
# include <winbase.h>
# include <errhandlingapi.h>
# include <fileapi.h>
#endif

#include "ODBCXX_Export.h"

#include "intellisense/odbcxx_project_headers.hh"

export module odbc.FileDescriptorDevice;

#if !defined MSVC_INTELLISENSE
import std;
import external.boost.iostreams;
import odbc.WindowsCategory;
#endif

namespace odbc
{
    export class ODBCXX_EXPORT FileDescriptorDevice
    {
    public:
#if defined WINDOWS
	using HandleType = HANDLE;
#else
	using HandleType = int;
#endif

	using char_type = char;
	using handle_type = HandleType;

	enum class Flags
	{
	    None,
	    CloseOnRelease,
	    AppendMode
	};

	friend std::underlying_type_t<Flags> operator +(Flags flags)
	{
	    return static_cast<std::underlying_type_t<Flags>>(flags);
	}

	FileDescriptorDevice() = default;

	FileDescriptorDevice(HandleType handle, Flags flags);
	~FileDescriptorDevice();

	void open(HandleType handle, Flags flags);
	bool isOpen() const;
	HandleType handle() const;
	void close();

    protected:
	static constexpr auto const MAX_DWORD = (std::numeric_limits<DWORD>::max)();

	FileDescriptorDevice(std::filesystem::path const &path, std::ios_base::openmode mode);
	FileDescriptorDevice(std::string const &path, std::ios_base::openmode mode);
	FileDescriptorDevice(char const *path, std::ios_base::openmode mode);
	FileDescriptorDevice(wchar_t const *path, std::ios_base::openmode mode);
	void open(std::filesystem::path const &path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(std::string const &path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(char const *path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(wchar_t const *path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	std::streamsize read(char *buffer, std::streamsize bufferSize);
	std::streamsize write(const char *buffer, std::streamsize bufferSize);
	std::streampos seek(ext::boost::iostreams::stream_offset off, std::ios_base::seekdir way);

	Flags flags { Flags::None };

#if defined WINDOWS
	HandleType fileHandle = INVALID_HANDLE_VALUE;
#else
	HandleType fileHhandle = -1;
#endif
    };
}

inline odbc::FileDescriptorDevice::~FileDescriptorDevice()
{
    close();
}

inline odbc::FileDescriptorDevice::HandleType odbc::FileDescriptorDevice::handle() const
{
    return fileHandle;
}

inline std::streampos odbc::FileDescriptorDevice::seek(ext::boost::iostreams::stream_offset off, std::ios_base::seekdir way)
{
#if defined WINDOWS
    const auto beg = std::ios_base::beg, end = std::ios_base::end, cur = std::ios_base::cur;

    LARGE_INTEGER endPosition { };

    if (!::SetFilePointerEx(handle(), LARGE_INTEGER { .QuadPart = off }, &endPosition, way == beg ? FILE_BEGIN : way == end ? FILE_END : FILE_CURRENT))
	throw std::system_error { windows_error_code() };

    return endPosition.QuadPart;
#else
# error "Not implemented"
#endif
}

inline std::streamsize odbc::FileDescriptorDevice::write(char const *buffer, std::streamsize bufferSize)
{
    if (+flags & +Flags::AppendMode)
	seek(0, std::ios_base::end);

#if defined WINDOWS
    auto pendingSize = bufferSize;

    while (pendingSize)
	if (DWORD dwWriteSize; ::WriteFile(handle(), buffer, (std::min<std::streamsize>)(bufferSize, MAX_DWORD), &dwWriteSize, NULL))
	{
	    pendingSize -= dwWriteSize;
	    buffer += dwWriteSize;
	}
	else
	    throw std::system_error { windows_error_code() };

    return bufferSize;
#else
# error "Not implemented"
#endif
}

inline std::streamsize odbc::FileDescriptorDevice::read(char *buffer, std::streamsize bufferSize)
{
#if defined WINDOWS
    auto pendingSize = bufferSize;

    while (pendingSize)
	if (DWORD dwReadSize, dwRequestSize = (std::min<std::streamsize>)(bufferSize, MAX_DWORD); ::ReadFile(handle(), buffer, dwRequestSize, &dwReadSize, NULL))
	{
	    pendingSize -= dwReadSize;
	    buffer += dwReadSize;

	    if (dwReadSize != dwRequestSize)
		break;
	}
	else
	    if (dwReadSize)
		throw std::system_error { windows_error_code() };

    return bufferSize - pendingSize;
#else
# error "Not implemented"
#endif
}

inline void odbc::FileDescriptorDevice::close()
{
#if defined  WINDOWS
    if (+flags & +Flags::CloseOnRelease && handle() != INVALID_HANDLE_VALUE)
	if (::CloseHandle(handle()))
	    fileHandle = INVALID_HANDLE_VALUE;
	else
	    if (!std::uncaught_exceptions())
		throw std::system_error { windows_error_code() };
#else
# error "Not implemented"
#endif
}

inline void odbc::FileDescriptorDevice::open(char const *path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    using std::ios_base;

    DWORD
	dwAccessMode = (mode & ios_base::in ? GENERIC_READ : 0u) | (mode & ios_base::out ? GENERIC_WRITE : 0u),
	dwShare = dwShareMode == MAX_DWORD ? mode & ios_base::out ? 0u : FILE_SHARE_READ : dwShareMode,
	dwOpenDisposition = mode & ios_base::trunc ? CREATE_ALWAYS : mode & ios_base::out ? OPEN_ALWAYS : OPEN_EXISTING;

    close();

    flags = Flags::CloseOnRelease;
    fileHandle = ::CreateFileA(path, dwAccessMode, dwShare, NULL, dwOpenDisposition, FILE_ATTRIBUTE_NORMAL, NULL);

    if (handle() == INVALID_HANDLE_VALUE)
	throw std::system_error { windows_error_code() };

    if (mode & ios_base::ate)
	seek(0, ios_base::end);

    if (mode & ios_base::app)
	flags = Flags { +flags | +Flags::AppendMode };
}

inline void odbc::FileDescriptorDevice::open(wchar_t const *path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    using std::ios_base;

    DWORD
	dwAccessMode = (mode & ios_base::in ? GENERIC_READ : 0u) | (mode & ios_base::out ? GENERIC_WRITE : 0u),
	dwShare = dwShareMode == MAX_DWORD ? mode & ios_base::out ? 0u : FILE_SHARE_READ : dwShareMode,
	dwOpenDisposition = mode & ios_base::trunc ? CREATE_ALWAYS : OPEN_EXISTING;

    close();

    flags = Flags::CloseOnRelease;
    fileHandle = ::CreateFileW(path, dwAccessMode, dwShare, NULL, dwOpenDisposition, FILE_ATTRIBUTE_NORMAL, NULL);

    if (handle() == INVALID_HANDLE_VALUE)
	throw std::system_error { windows_error_code() };

    if (mode & ios_base::ate)
	seek(0, ios_base::end);

    if (mode & ios_base::app)
	flags = Flags { +flags | +Flags::AppendMode };
}

inline void odbc::FileDescriptorDevice::open(std::string const &path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    open(path.c_str(), mode, dwShareMode);
}

inline void odbc::FileDescriptorDevice::open(std::filesystem::path const &path, std::ios_base::openmode mode, DWORD dwShareMode)
{
    open(path.generic_string(), mode, dwShareMode);
}

inline void odbc::FileDescriptorDevice::open(HandleType newHandle, Flags flags)
{
    close();

    this->flags = flags;
    fileHandle = newHandle;
}

inline bool odbc::FileDescriptorDevice::isOpen() const
{
#if defined WINDOWS
    return handle() != INVALID_HANDLE_VALUE;
#else
    return handle() != -1;
#endif
}

inline odbc::FileDescriptorDevice::FileDescriptorDevice(HandleType newHandle, Flags flags)
    : fileHandle(newHandle), flags(flags)
{
}

inline odbc::FileDescriptorDevice::FileDescriptorDevice(char const *path, std::ios_base::openmode mode)
{
    try
    {
	open(path, mode);
    }
    catch (...)
    {
	close();

	throw;
    }
}

inline odbc::FileDescriptorDevice::FileDescriptorDevice(wchar_t const *path, std::ios_base::openmode mode)
{
    try
    {
	open(path, mode);
    }
    catch (...)
    {
	close();

	throw;
    }
}

inline odbc::FileDescriptorDevice::FileDescriptorDevice(std::string const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path.c_str(), mode)
{
}

inline odbc::FileDescriptorDevice::FileDescriptorDevice(std::filesystem::path const &path, std::ios_base::openmode mode)
    : FileDescriptorDevice(path.generic_string().c_str(), mode)
{
}
