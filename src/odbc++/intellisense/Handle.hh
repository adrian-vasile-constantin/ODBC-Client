#if !defined(SQL_ODBCXX_HANDLE)
#define SQL_ODBCXX_HANDLE

#if defined(_WINDOWS) && defined(_M_AMD64) && !defined(_AMD64_)
# define _AMD64_
#endif

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class ODBCXX_EXPORT Handle
    {
    protected:
	SQLSMALLINT handleType;
	SQLHANDLE sqlHandle = SQL_NULL_HANDLE;
	Handle(SQLSMALLINT handleType, SQLHANDLE inputHandle);

	using string = std::string;
	using sqlstring = std::vector<SQLCHAR>;

	std::tuple<sqlstring, SQLINTEGER, sqlstring>
	    diagnosticRecord(SQLSMALLINT recordNumber);

    public:
	Handle(Handle const &other) = delete;
	Handle(Handle &&other) noexcept;
	Handle(SQLSMALLINT handleType, Handle const &inputHandle);
	~Handle();

	std::vector<std::tuple<string, SQLINTEGER, string>>
	    diagnosticRecords();

	Handle &operator =(Handle const &other) = delete;
	Handle &operator =(Handle &&other);
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_HANDLE)
