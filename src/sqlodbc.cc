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

#include "odbc++/WindowsCategory.hh"
#include "odbc++/SQLDiagnosticException.hh"
#include "odbc++/Environment.hh"
#include "odbc++/Connection.hh"

#include "odbc++/FileDescriptorDevice.hh"
#include "odbc++/FileDescriptorSource.hh"
#include "odbc++/FileDescriptorSink.hh"

export module sqlodbc;

#if !defined MSVC_INTELLISENSE
import std;
import external.boost.iostreams;
import Context;
import CommandHandler;
#endif

using std::string;
using std::string_view;
using std::exception;
using std::system_error;
using std::unique_ptr;
using std::getline;
using std::istream;
using std::ostream;
using std::streambuf;
using std::clog;
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::flush;
using std::find_if;
using std::map;
using namespace std::literals::string_literals;
namespace execution = std::execution;

using ext::boost::iostreams::input;
using ext::boost::iostreams::output;
using ext::boost::iostreams::stream_buffer;
using ext::boost::iostreams::filtering_streambuf;
using ext::boost::iostreams::newline_filter;
using ext::boost::iostreams::operator |;
namespace newline = ext::boost::iostreams::newline;

using Flags = odbc::FileDescriptorDevice::Flags;
using odbc::FileDescriptorSink;
using odbc::FileDescriptorSource;
using odbc::SQLDiagnosticException;
using odbc::Environment;
using odbc::Connection;

static auto ScanFirstWord(std::string const &line) -> string::const_iterator
{
    return find_if(execution::par_unseq, line.begin(), line.end(), [](char ch)
	{
	    return " \t\r\n\f\v"s.find(ch) != string::npos;
	});
}

static auto commandHandlers = map<string, HandlerFunctor *> { };

static auto executeCommand(Context &context, string const &inputLine) -> bool
try
{
    if (inputLine.empty() || *inputLine.cbegin() == '#')
	return true;

    if (inputLine == ".quit"s || inputLine == ".exit" || inputLine == ".close" || inputLine == "\x04"s /* Ctrl+D */)
	return false;

    if (inputLine == ".disconnect"s || inputLine == ".dc"s)
    {
	if (!context.conn->disconnect())
	    cout << "Not connected.\n";

	cout << '\n';

	return true;
    }

    auto it = ScanFirstWord(inputLine);
    auto handlerIt = commandHandlers.find(string(inputLine.begin(), it));

    if (handlerIt == commandHandlers.end())
	if (*inputLine.cbegin() == '!')
	    return executeCommand(context, ".shell "s + string(++inputLine.cbegin(), inputLine.cend()));
	else
	    clog << "No such command: " << inputLine << "\n\n";
    else
	(*handlerIt->second)(inputLine, it);

    return true;
}
catch (SQLDiagnosticException const &ex)
{
    clog << ex.what() << "\n\n";

    return true;
}
catch (exception const &ex)
{
    clog << "Error: " << ex.what() << "\n\n";

    return true;
}

static auto trimWs(string &inputLine) -> void
{
    auto it = inputLine.begin();

    while (it != inputLine.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    if (it != inputLine.begin())
	inputLine.erase(inputLine.begin(), it);

    auto jt = inputLine.rbegin();

    while (jt != inputLine.rend() && " \t\r\n\f\v"s.find(*jt) != string::npos)
	jt++;

    if (jt != inputLine.rbegin())
	inputLine.erase(jt.base(), inputLine.end());
}

static auto loadHandlers(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog) -> void
{
    CommandHandler *handler = CommandHandler::first;

    while (handler)
    {
	for (auto const &commandName: handler->commandNames())
	    commandHandlers.emplace(commandName, handler->mainFunctor(context, cin, cout, cerr, clog));

	handler = handler->next;
    }
}

static auto writePrompt(Context &context) -> string
{
    if (context.connections.size() == 1u)
    {
	switch (context.conn->connected())
	{
	case context.conn->Connected:
	    return "+"s;

	case context.conn->InProgress:
	    return "*"s;

	default:
	    return "-"s;
	}
    }

    auto prompt = string { };

    for (auto const &conn: context.connections)
    {
	if (&conn == context.conn)
	    prompt.append(1u, '[');

	prompt.append(1u, conn.connected() == conn.Connected ? '+' : conn.connected() == conn.InProgress ? '*' : '-');

	if (&conn == context.conn)
	    prompt.append(1u, ']');
    }

    return prompt;
}

static auto runInterpretterLoop(Context &context) -> int
try
{
    string inputLine;

    loadHandlers(context, cin, cout, cerr, clog);

    while (cin.good())
    {
	if (context.interactive)
	{
	    cout << "ODBC:" << writePrompt(context) << '>';
	    clog << flush;
	}

	getline(cin, inputLine);

	trimWs(inputLine);

	if (!executeCommand(context, inputLine))
	    break;
    }

    return EXIT_SUCCESS;
}
catch (system_error const &ex)
{
    clog << "Application error: " << ex.code().message() << '\n';

    return EXIT_FAILURE;
}
catch (exception const &ex)
{
    clog << "Application error: " << ex.what() << '\n';

    return EXIT_FAILURE;
}
catch (...)
{
    clog << "Application error!\nTerminated!\n";

    return EXIT_FAILURE;
}

extern "C++" auto main(int argc, char const *argv[]) -> int
try
{
    Context context;

    auto inputDescriptor = FileDescriptorSource { Context::nativeStandardInput(), Flags::None };
    auto
	outputDescriptor = FileDescriptorSink { Context::nativeStandardOutput(), Flags::None },
	logDescriptor    = FileDescriptorSink { Context::nativeStandardError(), Flags::None },
	errorDescriptor  = FileDescriptorSink { Context::nativeStandardError(), Flags::None };

#if defined WINDOWS
    constexpr auto targetNewLine = newline::dos;
#else
    constexpr auto targetNewLine = newline::posix;
#endif

    // auto inputStreamBuffer = filtering_streambuf<input> { newline_filter { targetNewLine } | inputDescriptor };
    auto outputStreamBuffer = filtering_streambuf<output> { newline_filter { targetNewLine } | outputDescriptor };
    auto logStreamBuffer = filtering_streambuf<output> { newline_filter { targetNewLine } | logDescriptor };
    auto errorStreamBuffer = filtering_streambuf<output> { newline_filter { targetNewLine } | errorDescriptor };
    auto inputStreamBuffer = stream_buffer<FileDescriptorSource> { inputDescriptor };
    // auto outputStreamBuffer = stream_buffer<FileDescriptorSink> {outputDescriptor };
    // auto errorStreamBuffer = stream_buffer<FileDescriptorSink> { errorDescriptor };
    

    context.overrideStandardStreamBuffers(inputStreamBuffer, outputStreamBuffer, logStreamBuffer, errorStreamBuffer);

    cin.exceptions(cin.exceptions() | cin.badbit);
    cout.exceptions(cout.exceptions() | cout.badbit);
    clog.exceptions(clog.exceptions() | clog.badbit);
    cerr.exceptions(cerr.exceptions() | cerr.badbit);

    auto exitCode = runInterpretterLoop(context);

    if (cin.bad() || cin.fail() && !cin.eof())
	return EXIT_FAILURE;

    return exitCode;
}
catch (exception const &ex)
{
    try
    {
	clog << "Application error: " << ex.what() << '\n';
    }
    catch (...)
    {
    }

    return EXIT_FAILURE;
}
catch (...)
{
    try
    {
	clog << "Application error!\nTerminated!\n";
    }
    catch (...)
    {
    }

    return EXIT_FAILURE;
}
