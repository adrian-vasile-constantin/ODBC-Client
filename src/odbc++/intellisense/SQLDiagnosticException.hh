#if !defined(SQL_ODBCXX_DIAGNOSTIC_EXCEPTION_HH)
#define SQL_ODBCXX_DIAGNOSTIC_EXCEPTION_HH

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class ODBCXX_EXPORT SQLDiagnosticException: public std::runtime_error
    {
    protected:
	std::vector<std::tuple<std::string, SQLINTEGER, std::string>>
	    records;

	mutable std::string recordListMessage;
    public:
	SQLINTEGER recordCount();
	std::tuple<std::string, SQLINTEGER, std::string> const
	    &record(unsigned recordNumber) const;
	std::string const &sqlState(unsigned recordNumber) const;
	SQLINTEGER nativeError(unsigned recordNumber) const;
	std::string const &message(unsigned recordNumber) const;

	// SQLDiagnosticException(std::vector<std::tuple<std::string, SQLINTEGER, std::string>> &&recods);
	SQLDiagnosticException(std::vector<std::tuple<std::string, SQLINTEGER, std::string>> const &recods);
	SQLDiagnosticException(Handle &sqlHandle);

	virtual char const *what() const override;
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_DIAGNOSTIC_EXCEPTION_HH)
