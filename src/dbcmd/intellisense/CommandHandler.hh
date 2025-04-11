#if !defined(DBCMD_COMMAND_HANDLER_HH)
#define DBCMD_COMMAND_HANDLER_HH

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

class HandlerFunctor;

class CommandHandler
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

class HandlerFunctor
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

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(DBCMD_COMMAND_HANDLER_HH)
