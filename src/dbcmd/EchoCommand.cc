module;

#include "intellisense/project_headers.hh"

export module EchoCommand;

#if !defined MSVC_INTELLISENSE
import std;
import Context;
import CommandHandler;
#endif

class EchoCommand: public CommandHandler
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

inline std::unique_ptr<HandlerFunctor> EchoCommand::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module: private;

using std::set;
using std::string;
using std::string_view;
using namespace std::literals::string_literals;

set<string> const &EchoCommand::commandNames() const
{
    static set<string> commands { ".echo", ".echoerr" };

    return commands;
}

string const &EchoCommand::helpSubject() const
{
    static string subjectLine = "\t.echo Text...				Show text on standard output on standard error"s;

    return subjectLine;
}

string const &EchoCommand::helpText() const
{
    static string textLines =
	"\t.echo Text...            Show text on standard output\n"
	"\t.echoerr Text...         Show text on standard error\n"s;

    return textLines;

}

void EchoCommand::Functor::operator ()(string const &command, string::const_iterator it)
{
    string_view cmd { command.begin(), it };

    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    if (cmd == ".echo"s)
	cout << string_view { it, command.end() } << "\n\n";
    else
	if (cmd == ".echoerr")
	    clog << string_view { it, command.end() } << "\n\n";
}

EchoCommand echoCommand;
