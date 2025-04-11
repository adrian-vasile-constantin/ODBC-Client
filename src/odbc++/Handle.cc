module;

#include "intellisense/odbcxx_project_headers.hh"

#include "ODBCXX_export.h"

export module odbc.Handle;

#if !defined MSVC_INTELLISENSE
import std;
import sql.cli;
#endif

namespace odbc
{
#if !defined MSVC_INTELLISENSE
    using sql::SQLCHAR;
    using sql::SQLSMALLINT;
    using sql::SQLINTEGER;
    using sql::SQLHANDLE;
    using sql::SQL_NULL_HANDLE;
    using sql::SQL_SUCCESS;
    using sql::SQL_SUCCESS_WITH_INFO;
    using sql::SQL_NO_DATA;
    using sql::SQL_NEED_DATA;
    using sql::SQL_ERROR;
    using sql::SQL_STILL_EXECUTING;
    using sql::SQL_INVALID_HANDLE;
    using sql::SQLAllocHandle;
    using sql::SQLFreeHandle;
#endif

    export class ODBCXX_EXPORT Handle
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

inline odbc::Handle::Handle(SQLSMALLINT handleType, SQLHANDLE inputHandle)
    : handleType(handleType)
{
    switch (SQLAllocHandle(handleType, inputHandle, &sqlHandle))
    {
    case SQL_SUCCESS:
    case SQL_SUCCESS_WITH_INFO:
	return;

    case SQL_INVALID_HANDLE:
	throw std::runtime_error("Invalid handle");

    default:
	throw std::runtime_error("SQL Error");
    }
}

inline odbc::Handle::Handle(SQLSMALLINT handleType, Handle const &inputHandle)
    : Handle(handleType, inputHandle.sqlHandle)
{
}

inline odbc::Handle::Handle(Handle &&other) noexcept
    : handleType(other.handleType), sqlHandle(std::exchange(other.sqlHandle, SQLHANDLE { SQL_NULL_HANDLE }))
{
}

inline odbc::Handle &odbc::Handle::operator =(Handle &&other)
{
    handleType = other.handleType;
    sqlHandle = other.sqlHandle;

    other.sqlHandle = SQL_NULL_HANDLE;

    return *this;
}

inline odbc::Handle::~Handle()
{
    if (sqlHandle != SQL_NULL_HANDLE)
    {
	SQLFreeHandle(handleType, sqlHandle);
	sqlHandle = SQL_NULL_HANDLE;
    }
}

module :private;

using std::begin;
using std::end;
using std::runtime_error;
using std::tuple;
using std::get;
using std::vector;
using namespace std::literals::string_literals;

#if !defined MSVC_INTELLISENSE
using sql::SQLGetDiagRec;
#endif

static char const
    invalidHandleMessage[] = "(Unable to read message from SQL diagnostic area from ODBC: SQL_INVALID_HANDLE)",
    sqlErrorMessage[]	   = "(Unable to read message from SQL diagnostic area from ODBC: SQL_ERROR)";

std::tuple<odbc::Handle::sqlstring, SQLINTEGER, odbc::Handle::sqlstring>
    odbc::Handle::diagnosticRecord(SQLSMALLINT recordNumber)
{
    SQLINTEGER nativeError = 0;
    sqlstring sqlState(6u, '\0');
    sqlstring message;
    SQLSMALLINT messageSize;

    switch (SQLGetDiagRec(handleType, sqlHandle, recordNumber, sqlState.data(), &nativeError, nullptr, 0, &messageSize))
    {
    case SQL_SUCCESS:
	if (!messageSize)
	{
	    sqlState.resize(5u);
	    return tuple { sqlState, nativeError, sqlstring { } };
	}
	// fall-through

    case SQL_SUCCESS_WITH_INFO:
	message.resize(messageSize + 1u);

	switch (SQLGetDiagRec(handleType, sqlHandle, recordNumber, sqlState.data(), &nativeError, message.data(), message.size(), &messageSize))
	{
	case SQL_SUCCESS:
	case SQL_SUCCESS_WITH_INFO:
	    sqlState.resize(5u);
	    message.resize(messageSize);
	    return tuple { sqlState, nativeError, message };

	case SQL_NO_DATA:
	    return tuple { sqlstring { }, 0, sqlstring { } };

	case SQL_INVALID_HANDLE:
	    return tuple { sqlstring { }, 0, sqlstring { begin(invalidHandleMessage), end(invalidHandleMessage) - 1u } };

	case SQL_ERROR:
	default:
	    return tuple { sqlstring { }, 0, sqlstring { begin(sqlErrorMessage), end(sqlErrorMessage) - 1u } };
	}

    case SQL_NO_DATA:
	return tuple { sqlstring { }, 0, sqlstring { } };

    case SQL_INVALID_HANDLE:
	return tuple { sqlstring { }, 0, sqlstring { begin(invalidHandleMessage), end(invalidHandleMessage) - 1u } };

    case SQL_ERROR:
    default:
	return tuple { sqlstring { }, 0, sqlstring { begin(sqlErrorMessage), end(sqlErrorMessage) - 1u } };
    }
}

auto odbc::Handle::diagnosticRecords() -> vector<tuple<string, SQLINTEGER, string>>
{
    vector<tuple<string, SQLINTEGER, string>>
	records;

    SQLSMALLINT recordNumber = 1;

    tuple<sqlstring, SQLINTEGER, sqlstring> record = diagnosticRecord(recordNumber++);

    while (get<0>(record).size())
    {
	records.emplace_back
	(
	    string(get<0>(record).begin(), get<0>(record).end()),
	    get<1>(record),
	    string(get<2>(record).begin(), get<2>(record).end())
	);

	record = diagnosticRecord(recordNumber++);
    }

    return records;
}
