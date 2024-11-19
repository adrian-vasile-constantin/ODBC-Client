#if !defined(DBCMD_CH_DIR_HH)
#define DBCMD_CH_DIR_HH

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

class ChDirCommand: public CommandHandler
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

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(DBCMD_CH_DIR_HH)
