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

export module CommandHandler;

#if !defined MSVC_INTELLISENSE
import std;
import odbc.Environment;
import odbc.Connection;
import Context;
#endif

using std::exchange;

export class HandlerFunctor;

export class CommandHandler
{
protected:
    std::unique_ptr<HandlerFunctor> functor;

public:
    template <typename ElemT>
    using set = std::set<ElemT>;

    template <typename ObjectT, typename DeleterT = std::default_delete<ObjectT>>
    using unique_ptr = std::unique_ptr<ObjectT, DeleterT>;

    using string = std::string;

    static CommandHandler *first;

    CommandHandler *next;

    CommandHandler();
    virtual ~CommandHandler();

    using istream = std::istream;
    using ostream = std::ostream;

    virtual set<string> const &commandNames() const = 0;
    virtual string const &helpSubject() const = 0;
    virtual string const &helpText() const = 0;
    virtual unique_ptr<HandlerFunctor> handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog) = 0;
    virtual HandlerFunctor *mainFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog);
};

export class HandlerFunctor
{
public:
    using string = std::string;
    using istream = std::istream;
    using ostream = std::ostream;

protected:
    CommandHandler *handler;
    odbc::Environment &env;
    std::vector<odbc::Connection> &connections;
    unsigned &connectionIndex;
    odbc::Connection *&conn;

    istream &cin;
    ostream &cout, &cerr, &clog;

public:
    HandlerFunctor(CommandHandler &handler, Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog);
    virtual ~HandlerFunctor();

    virtual auto commandHandler() -> CommandHandler *;
    virtual auto operator ()(string const &command, string::const_iterator it) -> void = 0;
};

inline HandlerFunctor::HandlerFunctor(CommandHandler &commandHandler, Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog):
    handler(&commandHandler),
    env(context.env),
    connections(context.connections),
    connectionIndex(context.connectionIndex),
    conn(context.conn),
    cin(cin),
    cout(cout),
    cerr(cerr),
    clog(clog)
{
}

inline HandlerFunctor::~HandlerFunctor()
{
}

inline auto HandlerFunctor::commandHandler() -> CommandHandler *
{
    return handler;
}

module :private;

CommandHandler *CommandHandler::first { };

CommandHandler::CommandHandler()
    : next(exchange(first, this))
{
}

CommandHandler::~CommandHandler()
{
    CommandHandler **command = &first;

    while (*command && *command != this)
	command = &(*command)->next;

    if (*command == this)
	*command = this->next;

    this->next = nullptr;
}

HandlerFunctor *CommandHandler::mainFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    if (!functor)
	functor = handlerFunctor(context, cin, cout, cerr, clog);

    return functor.get();
}
