#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include <cstdlib>
#include <string>
#include <exception>
#include <memory>
#include <iostream>
#include <algorithm>
#include <execution>
#include <map>

#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>

#include "odbc++/WindowsCategory.hh"
#include "odbc++/SQLDiagnosticException.hh"
#include "odbc++/Environment.hh"
#include "odbc++/Connection.hh"

#include "dbcmd/Context.hh"
#include "dbcmd/CommandHandler.hh"

using std::string;
using std::string_view;
using std::exception;
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

using enum boost::iostreams::file_descriptor_flags;
using boost::iostreams::file_descriptor_source;
using boost::iostreams::file_descriptor_sink;
using boost::iostreams::stream_buffer;

using odbc::SQLDiagnosticException;
using odbc::Environment;
using odbc::Connection;

static string::const_iterator ScanFirstWord(std::string const &line)
{
    return find_if(execution::par_unseq, line.begin(), line.end(), [](char ch)
	{
	    return " \t\r\n\f\v"s.find(ch) != string::npos;
	});
}

static map<string, HandlerFunctor *> commandHandlers;

bool executeCommand(Context &context, string const &inputLine)
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

void trimWs(string &inputLine)
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

static void loadHandlers(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    CommandHandler *handler = CommandHandler::first;

    while (handler)
    {
	for (auto const &commandName : handler->commandNames())
	    commandHandlers.emplace(commandName, handler->mainFunctor(context, cin, cout, cerr, clog));

	handler = handler->next;
    }
}

string writePrompt(Context &context)
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

    string prompt;

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

static int runInterpretterLoop(Context &context)
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

int main(int argc, char const *argv[])
try
{
    Context context;

    file_descriptor_source inputDescriptor { Context::nativeStandardInput(), never_close_handle };
    file_descriptor_sink
	outputDescriptor { Context::nativeStandardOutput(), never_close_handle },
	errorDescriptor  { Context::nativeStandardError(), never_close_handle };

    auto inputStreamBuffer = stream_buffer { inputDescriptor };
    auto outputStreamBuffer = stream_buffer { outputDescriptor };
    auto errorStreamBuffer = stream_buffer { errorDescriptor };
    auto &logStreamBuffer = errorStreamBuffer;

    context.overrideStandardStreamBuffers(inputStreamBuffer, outputStreamBuffer, logStreamBuffer, errorStreamBuffer);

    cin.exceptions(cin.exceptions() | cin.badbit);
    cout.exceptions(cout.exceptions() | cout.badbit);
    clog.exceptions(clog.exceptions() | clog.badbit);
    cerr.exceptions(cerr.exceptions() | cerr.badbit);

    int exitCode = runInterpretterLoop(context);

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
