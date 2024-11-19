module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include "intellisense/project_headers.hh"

#if defined WINDOWS
# include <windows.h>
#endif

#include "odbc++/Environment.hh"
#include "odbc++/Connection.hh"

export module Context;

#if !defined MSVC_INTELLISENSE
import std;
#endif

export class Context
{
public:
    static bool isStdInInteractive();

#if defined(_WINDOWS)
    using NativeDescriptor = HANDLE;
#else
    using NativeDescriptor = int;
#endif

    static NativeDescriptor nativeStandardInput();
    static NativeDescriptor nativeStandardOutput();
    static NativeDescriptor nativeStandardError();

    bool interactive;
    odbc::Environment env;
    std::vector<odbc::Connection> connections;
    unsigned connectionIndex = 0u;
    odbc::Connection *conn = nullptr;

    std::map<std::string, std::map<std::string, std::string>>
	drivers;

    constexpr static unsigned const STANDARD_STREAM_COUNT = 4u;

    auto overrideStandardStreamBuffers(std::streambuf &cinBuffer, std::streambuf &coutBuffer, std::streambuf &clogBuffer, std::streambuf &cerrBuffer)
	-> std::streambuf *const (&)[STANDARD_STREAM_COUNT];

    auto overrideStandardStreamBuffers(std::wstreambuf &cinBuffer, std::wstreambuf &coutBuffer, std::wstreambuf &clogBuffer, std::wstreambuf &cerrBuffer)
	-> std::streambuf *const (&)[STANDARD_STREAM_COUNT];

    auto restoreStandardStreamBuffers() -> std::tuple<std::streambuf *const (&)[STANDARD_STREAM_COUNT], std::wstreambuf *const (&)[STANDARD_STREAM_COUNT]>;
    void appendNewConnection();
    void deleteConnection(unsigned connectionIndex);

    Context(bool isInteractive = isStdInInteractive(), unsigned long ver = SQL_OV_ODBC3_80);
    ~Context();

protected:
    std::streambuf *streamBuffers[STANDARD_STREAM_COUNT] = { };
    std::wstreambuf *wstreamBuffers[STANDARD_STREAM_COUNT] = { };
};

inline Context::Context(bool isInteractive, unsigned long ver)
    : interactive(isInteractive), env(ver)
{
    appendNewConnection();
}

inline void Context::appendNewConnection()
{
    connections.emplace_back(env);
    connectionIndex = connections.size() - 1u;
    conn = &connections[connectionIndex];
}

inline void Context::deleteConnection(unsigned connectionIndex)
{
    if (connectionIndex < connections.size())
	connections.erase(connections.begin() + connectionIndex);
}

inline Context::~Context()
{
    restoreStandardStreamBuffers();
}

module :private;

using std::exchange;
using std::array;
using std::tuple;
using std::basic_ios;
using std::streambuf;
using std::wstreambuf;
using std::flush;
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::wcin;
using std::wcout;
using std::wclog;
using std::wcerr;
using std::views::enumerate;
using std::views::zip;

#if defined WINDOWS

bool Context::isStdInInteractive()
{
    return GetFileType(GetStdHandle(STD_INPUT_HANDLE)) == FILE_TYPE_CHAR;
}

auto Context::nativeStandardInput() -> NativeDescriptor
{
    return ::GetStdHandle(STD_INPUT_HANDLE);
}

auto Context::nativeStandardOutput() -> NativeDescriptor
{
    return ::GetStdHandle(STD_OUTPUT_HANDLE);
}

auto Context::nativeStandardError() -> NativeDescriptor
{
    return ::GetStdHandle(STD_ERROR_HANDLE);
}

#endif

auto Context::overrideStandardStreamBuffers
    (
	std::streambuf &cinBuffer,
	std::streambuf &coutBuffer,
	std::streambuf &clogBuffer,
	std::streambuf &cerrBuffer
    )
	-> streambuf * const (&)[STANDARD_STREAM_COUNT]
{
    cout << flush, clog << flush, cerr << flush;

    for (auto &&[saveBuffer, stream, buffer]: zip
		    (
			streamBuffers,
			array<basic_ios<char> *, STANDARD_STREAM_COUNT> { &cin, &cout, &clog, &cerr },
			array { &cinBuffer, &coutBuffer, &clogBuffer, &cerrBuffer }
		    ))
    {
	saveBuffer = stream->rdbuf(buffer);
    }

    return streamBuffers;
}

auto Context::restoreStandardStreamBuffers() -> tuple<streambuf * const (&)[STANDARD_STREAM_COUNT], wstreambuf * const (&)[STANDARD_STREAM_COUNT]>
{
    thread_local streambuf *localStreamBuffers[STANDARD_STREAM_COUNT];
    thread_local wstreambuf *localWStreamBuffers[STANDARD_STREAM_COUNT];

    cout << flush, clog << flush, cerr << flush;

    for (auto &&[saveBuffer, stream, localBuffer]: zip
		    (
			streamBuffers,
			array<basic_ios<char> *, STANDARD_STREAM_COUNT> { &cin, &cout, &clog, &cerr },
			localStreamBuffers
		    ))
    {
	localBuffer = saveBuffer ? stream->rdbuf(exchange(saveBuffer, nullptr)) : nullptr;
    }

    wcout << flush, wclog << flush, wcerr << flush;

    for (auto &&[saveBuffer, stream, localBuffer] : zip
		    (
			wstreamBuffers,
			array<basic_ios<wchar_t> *, STANDARD_STREAM_COUNT> { &wcin, &wcout, &wclog, &wcerr },
			localWStreamBuffers
		    ))
    {
	localBuffer = saveBuffer ? stream->rdbuf(exchange(saveBuffer, nullptr)) : nullptr;
    }

    return { localStreamBuffers, localWStreamBuffers };
}

auto Context::overrideStandardStreamBuffers
    (
	std::wstreambuf &cinBuffer,
	std::wstreambuf &coutBuffer,
	std::wstreambuf &clogBuffer,
	std::wstreambuf &cerrBuffer
    )
	-> streambuf * const (&)[STANDARD_STREAM_COUNT]
{
    for (auto stream: { &cout, &clog, &cerr})
	*stream << flush;

    for (auto &&[saveBuffer, stream, buffer]: zip
		    (
			wstreamBuffers,
			array<basic_ios<wchar_t> *, STANDARD_STREAM_COUNT> { &wcin, &wcout, &wclog, &wcerr },
			array { &cinBuffer, &coutBuffer, &clogBuffer, &cerrBuffer }
		    ))
    {
	saveBuffer = stream->rdbuf(buffer);
    }

    return streamBuffers;
}
