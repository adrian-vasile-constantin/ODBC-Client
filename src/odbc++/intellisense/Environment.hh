#if !defined(SQL_ODBCXX_ENVIRONMENT)
#define SQL_ODBCXX_ENVIRONMENT

#if defined(_WINDOWS) && defined(_M_AMD64) && !defined(_AMD64_)
# define _AMD64_
#endif

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class ODBCXX_EXPORT Environment: protected Handle
    {
    protected:
	friend class Connection;
	void FetchDriver(SQLUSMALLINT direction, std::pair<sqlstring, sqlstring> &driverInfo);
	void FetchDSN(SQLUSMALLINT direction, std::pair<sqlstring, sqlstring> &dsn);
	auto DataSourceNames(SQLUSMALLINT direction) -> std::list<std::pair<std::string, std::string>>;

    public:
	enum class Version: unsigned long
	{
	    ODBC2 = SQL_OV_ODBC2,
	    ODBC3 = SQL_OV_ODBC3,
	    ODBC3_80 = SQL_OV_ODBC3_80
	};

	Environment(Version ver);
	Environment(unsigned long ver = SQL_OV_ODBC3_80);
	auto drivers() -> std::map<std::string, std::map<std::string, std::string>>;
	auto userDSNs() -> std::list<std::pair<std::string, std::string>>;
	auto systemDSNs() -> std::list<std::pair<std::string, std::string>>;

	SQLHENV nativeHandle() const;

	using Handle::diagnosticRecord;
	using Handle::diagnosticRecords;

	template <typename StringT, typename CharT>
	    static std::map<std::string, std::string> splitAttributes(StringT const &inputLine, CharT separator = ';');
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_ENVIRONMENT)
