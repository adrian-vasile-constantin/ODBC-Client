module;

#include "intellisense/odbcxx_project_headers.hh"

#include "ODBCXX_export.h"

export module odbc.Environment;

#if !defined MSVC_INTELLISENSE
import std;
import sql.cli;
import odbc.Handle;
#endif

namespace odbc
{
#if !defined MSVC_INTELLISENSE
    using std::uintptr_t;

    using sql::SQLSMALLINT;
    using sql::SQLUSMALLINT;
    using sql::SQLHENV;
    using sql::SQL_HANDLE_ENV;
    using sql::SQL_NULL_HANDLE;
    using sql::SQL_ATTR_ODBC_VERSION;
    using sql::SQL_OV_ODBC2;
    using sql::SQL_OV_ODBC3;
    using sql::SQL_OV_ODBC3_80;
    using sql::SQLSetEnvAttr;
    using sql::SQL_FETCH_NEXT;
    using sql::SQL_FETCH_FIRST;
    using sql::SQL_FETCH_FIRST_USER;
    using sql::SQL_FETCH_FIRST_SYSTEM;
#endif

    export class ODBCXX_EXPORT Environment: protected Handle
    {
    protected:
	friend class Connection;
	auto FetchDriver(SQLUSMALLINT direction, std::pair<sqlstring, sqlstring> &driverInfo) -> void;
	auto FetchDSN(SQLUSMALLINT direction, std::pair<sqlstring, sqlstring> &dsn) -> void;
	auto DataSourceNames(SQLUSMALLINT direction) -> std::list<std::pair<std::string, std::string>> ;

    public:
	enum class Version: unsigned long
	{
	    ODBC2    = SQL_OV_ODBC2,
	    ODBC3    = SQL_OV_ODBC3,
	    ODBC3_80 = SQL_OV_ODBC3_80
	};

	Environment(Version ver);
	Environment(unsigned long ver = SQL_OV_ODBC3_80);
	auto drivers() -> std::map<std::string, std::map<std::string, std::string>>;
	auto userDSNs() -> std::list<std::pair<std::string, std::string>>;
	auto systemDSNs() -> std::list<std::pair<std::string, std::string>>;
	auto DSNs() -> std::list<std::pair<std::string, std::string>>;

	auto nativeHandle() const -> SQLHENV;

	using Handle::diagnosticRecord;
	using Handle::diagnosticRecords;

	template <typename StringT, typename CharT>
	    static auto splitAttributes(StringT const &inputLine, CharT separator = CharT { ';' }) -> std::map<std::string, std::string>;
    };
}

inline odbc::Environment::Environment(unsigned long ver)
    : Handle(SQL_HANDLE_ENV, SQL_NULL_HANDLE)
{
    SQLSetEnvAttr(sqlHandle, SQL_ATTR_ODBC_VERSION, reinterpret_cast<void *>(uintptr_t { ver }), -1);
}

inline odbc::Environment::Environment(Version ver)
    : Environment(std::to_underlying(ver))
{
}

inline auto odbc::Environment::nativeHandle() const -> SQLHENV
{
    return sqlHandle;
}

inline auto odbc::Environment::userDSNs() -> std::list<std::pair<std::string, std::string>>
{
    return DataSourceNames(SQL_FETCH_FIRST_USER);
}

inline auto odbc::Environment::systemDSNs() -> std::list<std::pair<std::string, std::string>>
{
    return DataSourceNames(SQL_FETCH_FIRST_SYSTEM);
}

inline auto odbc::Environment::DSNs() -> std::list<std::pair<std::string, std::string>>
{
    return DataSourceNames(SQL_FETCH_FIRST);
}

template<typename StringT, typename CharT>
    auto odbc::Environment::splitAttributes(StringT const &attributes, CharT separator) -> std::map<std::string, std::string>
{
    using std::string;
    auto it = attributes.begin();
    auto jt = std::find(std::execution::par_unseq, it, attributes.end(), separator);

    std::map<string, string> attributesMap;

    while (it != jt)
    {
	auto kt = std::find(std::execution::par_unseq, it, jt, '=');

	if (kt != jt)
	    attributesMap[string(it, kt)] = string(kt + 1, jt);
	else
	    attributesMap[string(it, jt)] = string();

	if (jt != attributes.end())
	{
	    it = ++jt;
	    jt = std::find(std::execution::par_unseq, it, attributes.end(), separator);
	}
	else
	    it = jt;
    }

    return attributesMap;
}

module: private;

using std::string;
using std::basic_string;
using std::vector;
using std::map;
using std::list;
using std::pair;
using std::runtime_error;
using std::find;
using std::move;

namespace execution = std::execution;

#if !defined MSVC_INTELLISENSE
using sql::SQL_SUCCESS;
using sql::SQL_SUCCESS_WITH_INFO;
using sql::SQL_INVALID_HANDLE;
using sql::SQL_NO_DATA;
using sql::SQL_ERROR;
using sql::SQL_FETCH_FIRST;
using sql::SQL_FETCH_NEXT;
using sql::SQL_FETCH_FIRST_USER;
using sql::SQL_FETCH_FIRST_SYSTEM;
using sql::SQLDrivers;
using sql::SQLDataSources;
#endif

auto odbc::Environment::FetchDriver(SQLUSMALLINT direction, pair<sqlstring, sqlstring> &driverInfo) -> void
{
    auto descLen = SQLSMALLINT { 0 }, attrLen = SQLSMALLINT { 0 };

    switch
	(
	    SQLDrivers
		(
		    sqlHandle, direction,
		    driverInfo.first.data(),  static_cast<SQLSMALLINT>(driverInfo.first.size()), &descLen,
		    driverInfo.second.data(), static_cast<SQLSMALLINT>(driverInfo.second.size()), &attrLen
		)
	)
    {
    case SQL_SUCCESS:
    case SQL_SUCCESS_WITH_INFO:
	driverInfo.first.pop_back();
	driverInfo.second.pop_back();
	return;

    case SQL_INVALID_HANDLE:
	throw runtime_error("Invalid handle");

    case SQL_NO_DATA:
	throw runtime_error("No driver info.");

    case SQL_ERROR:
    default:
	throw runtime_error("SQL Error.");
    }
}

auto odbc::Environment::FetchDSN(SQLUSMALLINT direction, pair<sqlstring, sqlstring> &dsn) -> void
{
    auto nameLen = SQLSMALLINT { 0 }, descLen = SQLSMALLINT { 0 };

    switch
	(
	    SQLDataSources
		(
		    sqlHandle, direction,
		    dsn.first.data(), static_cast<SQLSMALLINT>(dsn.first.size()), &nameLen,
		    dsn.second.data(), static_cast<SQLSMALLINT>(dsn.second.size()), &descLen
		)
	)
    {
    case SQL_SUCCESS:
    case SQL_SUCCESS_WITH_INFO:
	dsn.first.pop_back();
	dsn.second.pop_back();
	return;

    case SQL_NO_DATA:
	throw runtime_error("No driver info.");

    case SQL_INVALID_HANDLE:
	throw runtime_error("Invalid handle.");

    case SQL_ERROR:
    default:
	throw runtime_error("SQL Error.");
    }
}

static auto MakeDriverInfo(vector<SQLCHAR> &description, vector<SQLCHAR> &attributes) -> pair<string, map<string, string>>
{
    string strDescription, attributeName, attributeValue;

    strDescription.reserve(description.size());
    strDescription.assign(description.begin(), description.end());

    auto it = attributes.begin();
    auto jt = find(execution::par_unseq, it, attributes.end(), '\0');

    map<string, string> attributesMap;

    while (jt != attributes.end())
    {
	auto kt = find(execution::par_unseq, it, jt, '=');

	if (kt != jt)
	    attributesMap[string(it, kt)] = string(kt + 1, jt);
	else
	    attributesMap[string(it, jt)] = string();

	it = ++jt;
	jt = find(execution::par_unseq, it, attributes.end(), '\0');
    }

    return { move(strDescription), move(attributesMap) };
}

auto odbc::Environment::drivers() -> map<string, map<string, string>>
{
    auto descLen = SQLSMALLINT { 0 }, attrLen = SQLSMALLINT { 0 };
    vector<pair<sqlstring, sqlstring>> driverList;
    SQLUSMALLINT direction = SQL_FETCH_FIRST;

    do
    {
	switch (SQLDrivers(sqlHandle, direction, nullptr, 0, &descLen, nullptr, 0, &attrLen))
	{
	case SQL_SUCCESS:
	case SQL_SUCCESS_WITH_INFO:
	    driverList.emplace_back(sqlstring(descLen + 1u), sqlstring(attrLen + 1u));
	    break;

	case SQL_NO_DATA:
	    descLen = -1;
	    break;

	case SQL_INVALID_HANDLE:
	    throw runtime_error("Invalid handle");

	case SQL_ERROR:
	    throw runtime_error("SQL Error");
	}

	direction = SQL_FETCH_NEXT;
    }
    while (descLen >= 0);

    map<string, map<string, string>> drivers;

    for (auto &driverInfo: driverList)
    {
	FetchDriver(&driverInfo == &driverList.front() ? SQL_FETCH_FIRST : SQL_FETCH_NEXT, driverInfo);
	drivers.emplace(MakeDriverInfo(driverInfo.first, driverInfo.second));
    }

    return drivers;
}

static inline auto MakeDsnInfo(vector<SQLCHAR> &name, vector<SQLCHAR> &desc) -> pair<string, string>
{
    return { string { name.begin(), name.end() }, string { desc.begin(), desc.end() } };
}

auto odbc::Environment::DataSourceNames(SQLUSMALLINT direction) -> list<pair<string, string>>
{
    auto nameLen = SQLSMALLINT { 0 }, descLen = SQLSMALLINT { 0 };
    auto dsnList = list<pair<sqlstring, sqlstring>> { };
    auto nextDirection = SQLUSMALLINT { direction };

    do
    {
	switch (SQLDataSources(sqlHandle, nextDirection, nullptr, 0, &nameLen, nullptr, 0, &descLen))
	{
	case SQL_SUCCESS:
	case SQL_SUCCESS_WITH_INFO:
	    dsnList.emplace_back(sqlstring(nameLen + 1u), sqlstring(descLen + 1u));
	    break;

	case SQL_NO_DATA:
	    nameLen = -1;
	    break;

	case SQL_INVALID_HANDLE:
	    throw runtime_error("Invalid handle.");

	case SQL_ERROR:
	default:
	    throw runtime_error("SQL Error.");
	}

	nextDirection = SQL_FETCH_NEXT;
    }
    while (nameLen >= 0);

    auto dsns = list<pair<string, string>> { };

    nextDirection = SQLUSMALLINT { direction };

    for (auto &dsnInfo: dsnList)
    {
	FetchDSN(nextDirection, dsnInfo);
	nextDirection = SQL_FETCH_NEXT;
	dsns.emplace_back(MakeDsnInfo(dsnInfo.first, dsnInfo.second));
    }

    return dsns;
}
