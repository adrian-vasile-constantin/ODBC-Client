#if !defined(DBCMD_CONTEXT_HH)
#define DBCMD_CONTEXT_HH

#if defined __INTELLISENSE__

// For MS IntelliseSense only

class Context
{
public:
    static bool isStdInInteractive();
    
#if defined(_WINDOWS)
    using NativeDescriptor = HANDLE;
#else
    using NativeDescriptor = int;
#endif

    static NativeDescriptor nativeStandardInput();
    static NativeDescriptor nativeStandardOutput();
    static NativeDescriptor nativeStandardError();

    bool interactive;
    odbc::Environment env;
    std::vector<odbc::Connection> connections;
    unsigned connectionIndex = 0u;
    odbc::Connection *conn = nullptr;

    std::map<std::string, std::map<std::string, std::string>>
	drivers;

    constexpr static unsigned const STANDARD_STREAM_COUNT = 4u;

    auto overrideStandardStreamBuffers(std::streambuf &cinBuffer, std::streambuf &coutBuffer, std::streambuf &clogBuffer, std::streambuf &cerrBuffer)
	-> std::streambuf * const (&)[STANDARD_STREAM_COUNT];

    auto overrideStandardStreamBuffers(std::wstreambuf &cinBuffer, std::wstreambuf &coutBuffer, std::wstreambuf &clogBuffer, std::wstreambuf &cerrBuffer)
	-> std::streambuf *const (&)[STANDARD_STREAM_COUNT];

    auto restoreStandardStreamBuffers() -> std::tuple<std::streambuf * const (&)[STANDARD_STREAM_COUNT], std::wstreambuf * const (&)[STANDARD_STREAM_COUNT]>;
    void appendNewConnection();
    void deleteConnection(unsigned connectionIndex);

    Context(bool isInteractive = isStdInInteractive(), unsigned long ver = SQL_OV_ODBC3_80);
    ~Context();

protected:
    std::streambuf *streamBuffers[STANDARD_STREAM_COUNT] = { };
    std::wstreambuf *wstreamBuffers[STANDARD_STREAM_COUNT] = { };
};

#endif

#endif
