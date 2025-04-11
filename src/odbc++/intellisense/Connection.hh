#if !defined(SQL_ODBCXX_CONNECTION)
#define SQL_ODBCXX_CONNECTION

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class ODBCXX_EXPORT Connection: protected Handle
    {
    public:
	enum State
	{
	    Disconnected, InProgress, Connected
	};

    protected:
	State state = State::Disconnected;

	enum class BrowseConnectResult
	{
	    Connected,
	    Again,
	    More
	}
	    nativeBrowseConnect(std::span<SQLCHAR> request, sqlstring &result);

	std::map<std::string, std::string> browseConnect(std::span<SQLCHAR> request);

    public:
	Connection(Environment &env);
	Connection(Connection const &other) = delete;
	Connection(Connection &&other) = default;
	~Connection();

	SQLHDBC nativeHandle() const;
	using Handle::diagnosticRecord;
	using Handle::diagnosticRecords;

	Connection &operator =(Connection const &other) = delete;
	Connection &operator =(Connection &&other) = default;

	std::map<std::string, std::string> browseConnect(std::map<std::string, std::string> const &request);
	bool disconnect();
	State connected() const noexcept;
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_CONNECTION)
