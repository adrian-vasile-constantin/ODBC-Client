#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include <array>
#include <tuple>
#include <utility>
#include <initializer_list>
#include <streambuf>
#include <ios>
#include <iomanip>
#include <iostream>
#include <ranges>

#include "Context.hh"

#if defined(_WINDOWS)
# include <windows.h>

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
