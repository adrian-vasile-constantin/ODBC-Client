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
# include <windef.h>
# include <WinBase.h>
# include <processenv.h>
#endif


export module EnvCommand;

#if !defined MSVC_INTELLISENSE
import std;

#if defined WINDOWS
import odbc.WindowsCategory;
#endif

import Context;
import CommandHandler;
#endif

class EnvCommand: public CommandHandler
{
protected:
    class Functor: public HandlerFunctor
    {
    public:
	using HandlerFunctor::HandlerFunctor;
	virtual void operator ()(string const &command, string::const_iterator it) override;
    };

    virtual set<string> const &commandNames() const override;
    virtual string const &helpSubject() const override;
    virtual string const &helpText() const override;
    virtual unique_ptr<HandlerFunctor> handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog) override;
};

inline std::unique_ptr<HandlerFunctor> EnvCommand::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module :private;

using std::unique_ptr;
using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::string;
using std::string_view;
using std::find;
using std::reduce;
using std::runtime_error;
using std::ostream;
using std::getenv;
using std::system_error;
using namespace std::literals::string_literals;
namespace execution = std::execution;

#if defined WINDOWS
using odbc::windows_error_code;
#endif

#if defined WINDOWS
constexpr char const pathListDelimiter = ';';
#else
constexpr char const pathListDelimiter = ':';
#endif

set<string> const &EnvCommand::commandNames() const
{
    static set<string> const names { ".env", ".pathEnv", ".unsetEnv" };

    return names;
}

string const &EnvCommand::helpSubject() const
{
    static string subjectLine = "\t.env					Display or update environment variables";

    return subjectLine;
}
string const &EnvCommand::helpText() const
{
    static string textLines =
	"\t.env                                     List environment variables and their values\n"
	"\t.env      <variable_name [= value]>      Display or set an environment variable\n"
	"\t.unsetEnv <variable_name>                Remove an environment variable\n"
	"\t.pathEnv  <variable_name>                Show a path list variable like PATH, one path per line\n"
	"\t.pathEnv  <variable_name> -= <value>     Update a path variable to remove a single path from list\n"
	"\t.pathEnv  <variable_name> += <value>     Update a path variable to add a single path to the list\n"s;

    return textLines;
}

static tuple<string, string, string> parseEnvCommand(string const &command, string::const_iterator it)
{
    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    string_view varName, applyOp, newValue;

    if (it != command.end())
    {
	auto jt = find(execution::par_unseq, it, command.cend(), '=');

	if (jt != command.end())
	{
	    switch (*(jt - 1))
	    {
	    case '-':
	    case '+':
		jt--;
		applyOp = string_view { jt, jt + 2 };
		break;

	    default:
		applyOp = string_view { jt, jt + 1 };
		break;
	    }
	}

	if (jt != it)
	{
	    auto kt = jt - 1u;

	    while (" \t\r\n\f\v"s.find(*kt) != string::npos)
		kt--;

	    varName = string_view { it, ++kt };
	}

	if (jt != command.end())
	{
	    jt += applyOp.size();

	    while (jt != command.end() && " \t\r\n\f\v"s.find(*jt) != string::npos)
		jt++;

	    newValue = string_view { jt, command.end() };
	}
    }

    return tuple { string { varName }, string { applyOp }, string { newValue } };
}

#if defined(_WINDOWS)
extern "C" int __cdecl putenv(char const *_EnvString);		// Not exposed with std module
#endif

static void removeEnvVar(string const &varName)
{
#if defined(_WINDOWS)
    if (putenv((varName + "="s).c_str()) < 0)
	throw runtime_error("Error removing environment variable"s);
#else
    unsetenv(varName.c_str());
#endif
}

static void setEnvVar(string const &varName, string const &newValue)
{
#if defined(_WINDOWS)
    if (putenv((varName + "="s + newValue).c_str()) < 0)
	throw runtime_error("Error setting environment variable"s);
#else
    string envLine = varName + "="s + newValue;
    setenv(varName.c_str(), newValue.c_str());
#endif
}

static void showEnvironment(ostream &cout)
{
#if defined WINDOWS

    unique_ptr<CHAR [], decltype((FreeEnvironmentStrings))> env { GetEnvironmentStrings(), FreeEnvironmentStrings };

    if (CHAR const *pEnv = env.get())
    {
	while (unsigned len = strlen(pEnv))
	{
	    if (*pEnv != '=')	    // some weired strings beginging with = are found at the beginning of the block under VS
		cout << '\t' << string_view { pEnv, pEnv + len } << '\n';

	    pEnv += len + 1u;
	}
    }
    else
	throw system_error { windows_error_code(), "Failed to get environment table." };

#else
    extern char **environ;

    char **var = environ;

    map<string, string> variables;

    while (*var)
    {
	char *p = *var;

	while (*p && *p != '=')
	    p++;

	if (*p)
	    variables.emplace(string { *var, p - 1 }, string(++p));
	else
	    variables.emplace(string { *var, p - 1 }, string());

	var++;
    }

    for (auto const &envPair : variables)
	cout << '\t' << envPair.first << '=' << envPair.second << '\n';
#endif

    cout << '\n';
}

static void showEnvironment(string const &varName, ostream &cout)
{
    char const *env = std::getenv(varName.c_str());

    if (!env)
	cout << '\n';
    else
        cout <<  env << "\n\n";
}

static vector<string> splitNativePathList(char const *pathList)
{
    vector<string> list;

    if (!pathList)
	pathList = "";

    while (*pathList)
    {
	while (*pathList == pathListDelimiter)
	    pathList++;

	if (*pathList)
	{
	    char const *p = pathList;

	    while (*p && *p != pathListDelimiter)
		p++;

	    list.emplace_back(pathList, p);

	    pathList = p;
	}
    }

    return list;
}

static void showPathEnvironment(vector<string> const &pathList, ostream &cout)
{
    for (auto const &path: pathList)
	cout << '\t' << path << '\n';

    cout << '\n';
}

static void adjustPathEnvironment(string const &varName, string const &applyOp, string const &newValue)
{
    vector<string> pathList = splitNativePathList(getenv(varName.c_str()));

    auto it = find(execution::par_unseq, pathList.begin(), pathList.end(), newValue);

    if (it != pathList.end() && applyOp == "-="s)
    {
	pathList.erase(it);
	string value = reduce(execution::seq, pathList.begin(), pathList.end(), string(), [](auto const &leftStr, auto const &rightStr) -> string
	    {
		return leftStr.empty() ? rightStr : leftStr + pathListDelimiter + rightStr;
	    });

	setEnvVar(varName, value);
    }
    else
	if (it == pathList.end() && applyOp == "+="s)
	{
	    pathList.push_back(newValue);
	    string value = reduce(execution::seq, pathList.begin(), pathList.end(), string(), [](auto const &leftStr, auto const &rightStr) -> string
		{
		    return leftStr.empty() ? rightStr : leftStr + pathListDelimiter + rightStr;
		});

	    setEnvVar(varName, value);
	}
}

void EnvCommand::Functor::operator ()(string const &command, string::const_iterator it)
{
    string_view cmd { command.cbegin(), it };

    auto [varName, applyOp, newValue] = parseEnvCommand(command, it);

    if (varName.empty() && applyOp.size())
	throw runtime_error("Environment variable name expected before assignament operator.");

    if (cmd == ".unsetEnv"s)
	if (applyOp.size())
	    throw runtime_error("Unexpected assignament operator for .unsetEnv command.");
	else
	{
	    removeEnvVar(varName);
	    cout << '\n';
	}
    else
	if (cmd == ".env")
	    if (applyOp.empty())
		if (varName.empty())
		    showEnvironment(cout);
		else
		    showEnvironment(varName, cout);
	    else
		if (applyOp != "="s)
		    throw runtime_error("Unexpected compund assignment.");
		else
		{
		    setEnvVar(varName, newValue);
		    cout << '\n';
		}
	else
	    if (cmd == ".pathEnv"s)
		if (varName.empty())
		    showPathEnvironment(splitNativePathList(getenv("PATH")), cout);
		else
		    if (applyOp.empty())
			showPathEnvironment(splitNativePathList(getenv(varName.c_str())), cout);
		    else
			if (applyOp == "="s)
			    throw runtime_error("Expected compound assignment operator or no operator.");
			else
			    {
				adjustPathEnvironment(varName, applyOp, newValue);
				cout << '\n';
			    }
}

EnvCommand envCommand;
