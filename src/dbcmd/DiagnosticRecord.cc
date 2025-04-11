module;

#include "intellisense/project_headers.hh"

export module DiagnosticRecord;

#if !defined MSVC_INTELLISENSE
import std;
import CommandHandler;
import odbc.SQLDiagnosticException;
#endif

class DiagnosticRecord: public CommandHandler
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

inline std::unique_ptr<HandlerFunctor> DiagnosticRecord::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module :private;

using std::set;
using std::string;
using std::string_view;
using std::runtime_error;
using namespace std::literals::string_literals;

using odbc::SQLDiagnosticException;

set<string> const &DiagnosticRecord::commandNames() const
{
    static set<string> nameList { ".diagnosticRecord"s, ".diag"s };

    return nameList;
}

string const &DiagnosticRecord::helpSubject() const
{
    static string const subjectLine = "\t.diagnosticRecord			Outputs the last SQL diagnostic messages"s;

    return subjectLine;
}

string const &DiagnosticRecord::helpText() const
{
    static string const textLines =
	"\t.diagnosticRecord   [--connection | --environment ]    Outputs diagnostic messages from the last SQL command.\n"
	"\t.diag               [--conn | --env ]\n"s;

    return textLines;
}

void DiagnosticRecord::Functor::operator ()(string const &command, string::const_iterator it)
{
    string_view cmd { command.cbegin(), it };

    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    string subjectHandle { it, command.end() };

    static set<string> optionNames { "--connection"s, "--conn"s, "--environment"s, "--env"s, "--statement"s, "--stmt"s };

    if (!subjectHandle.empty() && optionNames.find(subjectHandle) == optionNames.end())
	throw runtime_error("Option not supported.");

    if (subjectHandle == "--statement"s || subjectHandle == "--stmt"s)
	throw runtime_error("Not implemented.");

    if (subjectHandle.empty() || subjectHandle == "--environment"s || subjectHandle == "--env"s)
    {
	SQLDiagnosticException exc(env.diagnosticRecords());

	if (exc.recordCount())
	    cout << exc.what() << '\n';
    }

    if (subjectHandle.empty() || subjectHandle == "--connection"s || subjectHandle == "--conn"s)
    {
	SQLDiagnosticException exc(conn->diagnosticRecords());

	if (exc.recordCount())
	    cout << exc.what() << '\n';
    }

    cout << '\n';
}

DiagnosticRecord diagnosticRecord;
