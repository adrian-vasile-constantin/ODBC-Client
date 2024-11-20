module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#if defined WINDOWS
# include <windef.h>
#endif

#include <sql.h>
#include <sqlext.h>
#include <sqlucode.h>

#include "intellisense/odbcxx_project_headers.hh"

#include "ODBCXX_export.h"

export module odbc.Environment;

#if !defined MSVC_INTELLISENSE
import std;
import odbc.Handle;
#endif

namespace odbc
{
    export class ODBCXX_EXPORT Environment: protected Handle
    {
    protected:
	friend class Connection;
	void FetchDriver(SQLUSMALLINT direction, std::pair<sqlstring, sqlstring> &driverInfo);

    public:
	enum class Version: unsigned long
	{
	    ODBC2    = SQL_OV_ODBC2,
	    ODBC3    = SQL_OV_ODBC3,
	    ODBC3_80 = SQL_OV_ODBC3_80
	};

	Environment(Version ver);
	Environment(unsigned long ver = SQL_OV_ODBC3_80);
	std::map<std::string, std::map<std::string, std::string>> drivers();

	SQLHENV nativeHandle() const;

	using Handle::diagnosticRecord;
	using Handle::diagnosticRecords;

	template <typename StringT, typename CharT>
	static std::map<std::string, std::string> splitAttributes(StringT const &inputLine, CharT separator = ';');
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

inline SQLHENV odbc::Environment::nativeHandle() const
{
    return sqlHandle;
}

template<typename StringT, typename CharT>
std::map<std::string, std::string> odbc::Environment::splitAttributes(StringT const &attributes, CharT separator)
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
using std::pair;
using std::runtime_error;
using std::find;
using std::move;

namespace execution = std::execution;

void odbc::Environment::FetchDriver(SQLUSMALLINT direction, pair<sqlstring, sqlstring> &driverInfo)
{
    SQLSMALLINT descLen = 0, attrLen = 0;

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

    case SQL_NO_DATA:
	throw runtime_error("No driver info.");

    case SQL_ERROR:
    default:
	throw runtime_error("SQL Error.");
    }
}

static pair<string, map<string, string>> MakeDriverInfo(vector<SQLCHAR> &description, vector<SQLCHAR> &attributes)
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
    SQLSMALLINT descLen = 0, attrLen = 0;
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
