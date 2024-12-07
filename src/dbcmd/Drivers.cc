module;

#include "intellisense/project_headers.hh"

export module DriversCommand;

#if !defined MSVC_INTELLISENSE
import std;
import odbc.Environment;
import odbc.Connection;
import Context;
import CommandHandler;
#endif

class Drivers: public CommandHandler
{
protected:
    class Functor: public HandlerFunctor
    {
    public:
	using HandlerFunctor::HandlerFunctor;
	virtual void operator ()(string const &command, string::const_iterator it) override;
    };

public:
    virtual set<string> const &commandNames() const override;
    virtual string const &helpSubject() const override;
    virtual string const &helpText() const override;
    virtual unique_ptr<HandlerFunctor> handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog) override;
};

inline std::unique_ptr<HandlerFunctor> Drivers::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module: private;

using std::set;
using std::string;
using std::cout;
using std::setw;
using std::left;
using std::max_element;
using namespace std::literals::string_literals;
namespace execution = std::execution;

using odbc::Environment;
using odbc::Connection;

set<string> const &Drivers::commandNames() const
{
    static set<string> names { ".drivers" };

    return names;
}

string const &Drivers::helpSubject() const
{
    static string subjectLine = "\t.drivers [--brief]			List available ODBC drivers";

    return subjectLine;
}
string const &Drivers::helpText() const
{
    static string textLines =
	"\t.drivers			List available ODBC drivers with their attributes, one per line\n"
	"\t.drivers --brief		List available ODBC drivers names (only)\n"s;

    return textLines;
}

void Drivers::Functor::operator ()(string const &command, string::const_iterator it)
{
    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    string cmdArg { it, command.end() };
    bool brief = false;

    if (cmdArg == "--brief"s)
	brief = true;
    else
	if (cmdArg.size())
	{
	    clog << "Option not supported: " << cmdArg << "\n\n";
	    return;
	}

    for (auto const &[description, attributes]: env.drivers())
    {
	cout << description.data() << (brief ? "" : ":") << '\n';

	if (!brief)
	{
	    auto it = max_element(execution::par_unseq, attributes.begin(), attributes.end(), [](auto const &elem, auto const &other)
		{
		    return elem.first.size() < other.first.size();
		});

	    auto maxNameWidth = it == attributes.end() ? 0u : it->first.size();

	    for (auto const &attribute : attributes)
		cout << '\t' << setw(maxNameWidth) << left << attribute.first << " => " << attribute.second << '\n';

	    cout << '\n';
	}
    }

    if (brief)
	cout << '\n';
}

static Drivers driversCmd;
