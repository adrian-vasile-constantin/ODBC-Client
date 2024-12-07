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

export module sql.cli;

namespace
{
    constexpr SQLHANDLE const
	local_SQL_NULL_HANDLE = SQL_NULL_HANDLE;

    constexpr auto const
	local_SQL_NTS = SQL_NTS;

    constexpr auto const
	local_SQL_SUCCESS	    = SQL_SUCCESS,
	local_SQL_SUCCESS_WITH_INFO = SQL_SUCCESS_WITH_INFO,
	local_SQL_NO_DATA	    = SQL_NO_DATA,
	local_SQL_NEED_DATA	    = SQL_NEED_DATA,
	local_SQL_ERROR		    = SQL_ERROR,
	local_SQL_STILL_EXECUTING   = SQL_STILL_EXECUTING,
	local_SQL_INVALID_HANDLE    = SQL_INVALID_HANDLE;

    constexpr auto const
	local_SQL_HANDLE_ENV	    = SQL_HANDLE_ENV,
	local_SQL_HANDLE_SENV	    = SQL_HANDLE_SENV,
	local_SQL_HANDLE_DBC	    = SQL_HANDLE_DBC,
	local_SQL_HANDLE_STMT	    = SQL_HANDLE_STMT,
	local_SQL_HANDLE_DESC	    = SQL_HANDLE_DESC;

    constexpr auto const
	local_SQL_ATTR_ODBC_VERSION       = SQL_ATTR_ODBC_VERSION,
	local_SQL_ATTR_CONNECTION_POOLING = SQL_ATTR_CONNECTION_POOLING,
	local_SQL_ATTR_CP_MATCH           = SQL_ATTR_CP_MATCH,
	local_SQL_ATTR_APPLICATION_KEY    = SQL_ATTR_APPLICATION_KEY;

    constexpr auto const
	local_SQL_CP_OFF             = SQL_CP_OFF,
	local_SQL_CP_ONE_PER_DRIVER  = SQL_CP_ONE_PER_DRIVER,
	local_SQL_CP_ONE_PER_HENV    = SQL_CP_ONE_PER_HENV,
	local_SQL_CP_DRIVER_AWARE    = SQL_CP_DRIVER_AWARE,
	local_SQL_CP_DEFAULT         = SQL_CP_DEFAULT;

    constexpr auto const
	local_SQL_CP_STRICT_MATCH  = SQL_CP_STRICT_MATCH,
	local_SQL_CP_RELAXED_MATCH = SQL_CP_RELAXED_MATCH,
	local_SQL_CP_MATCH_DEFAULT = SQL_CP_MATCH_DEFAULT;

    constexpr auto const
	local_SQL_OV_ODBC2	    = SQL_OV_ODBC2,
	local_SQL_OV_ODBC3	    = SQL_OV_ODBC3,
	local_SQL_OV_ODBC3_80	    = SQL_OV_ODBC3_80;

    constexpr auto const
	local_SQL_ATTR_ACCESS_MODE	   = SQL_ATTR_ACCESS_MODE,
	local_SQL_ATTR_AUTOCOMMIT	   = SQL_ATTR_AUTOCOMMIT,
	local_SQL_ATTR_CONNECTION_TIMEOUT  = SQL_ATTR_CONNECTION_TIMEOUT,
	local_SQL_ATTR_CURRENT_CATALOG     = SQL_ATTR_CURRENT_CATALOG,
	local_SQL_ATTR_DISCONNECT_BEHAVIOR = SQL_ATTR_DISCONNECT_BEHAVIOR,
	local_SQL_ATTR_ENLIST_IN_DTC	   = SQL_ATTR_ENLIST_IN_DTC,
	local_SQL_ATTR_ENLIST_IN_XA	   = SQL_ATTR_ENLIST_IN_XA,
	local_SQL_ATTR_LOGIN_TIMEOUT	   = SQL_ATTR_LOGIN_TIMEOUT,
	local_SQL_ATTR_ODBC_CURSORS	   = SQL_ATTR_ODBC_CURSORS,
	local_SQL_ATTR_PACKET_SIZE	   = SQL_ATTR_PACKET_SIZE,
	local_SQL_ATTR_QUIET_MODE	   = SQL_ATTR_QUIET_MODE,
	local_SQL_ATTR_TRACE		   = SQL_ATTR_TRACE,
	local_SQL_ATTR_TRACEFILE	   = SQL_ATTR_TRACEFILE,
	local_SQL_ATTR_TRANSLATE_LIB	   = SQL_ATTR_TRANSLATE_LIB,
	local_SQL_ATTR_TRANSLATE_OPTION    = SQL_ATTR_TRANSLATE_OPTION,
	local_SQL_ATTR_TXN_ISOLATION	   = SQL_ATTR_TXN_ISOLATION,
	local_SQL_ATTR_CONNECTION_DEAD     = SQL_ATTR_CONNECTION_DEAD,
	local_SQL_ATTR_ANSI_APP		   = SQL_ATTR_ANSI_APP,
	local_SQL_ATTR_RESET_CONNECTION    = SQL_ATTR_RESET_CONNECTION,
	local_SQL_ATTR_ASYNC_DBC_EVENT     = SQL_ATTR_ASYNC_DBC_EVENT;

    constexpr auto const
	local_SQL_FETCH_NEXT      = SQL_FETCH_NEXT,
	local_SQL_FETCH_FIRST     = SQL_FETCH_FIRST,
	local_SQL_FETCH_LAST      = SQL_FETCH_LAST,
	local_SQL_FETCH_PRIOR     = SQL_FETCH_PRIOR,
	local_SQL_FETCH_ABSOLUTE  = SQL_FETCH_ABSOLUTE,
	local_SQL_FETCH_RELATIVE  = SQL_FETCH_RELATIVE;

    constexpr auto const
	local_SQL_COMMIT	  = SQL_COMMIT,
	local_SQL_ROLLBACK        = SQL_ROLLBACK;

    constexpr SQLHENV  const local_SQL_NULL_HENV       = SQL_NULL_HENV;
    constexpr SQLHDBC  const local_SQL_NULL_HDBC       = SQL_NULL_HDBC;
    constexpr SQLHSTMT const local_SQL_NULL_HSTMT      = SQL_NULL_HSTMT;
    constexpr SQLHDESC const local_SQL_NULL_HDESC      = SQL_NULL_HDESC;
}

#undef SQL_NULL_HANDLE

#undef SQL_NTS

#undef SQL_SUCCESS
#undef SQL_SUCCESS_WITH_INFO
#undef SQL_NO_DATA
#undef SQL_NEED_DATA
#undef SQL_ERROR
#undef SQL_STILL_EXECUTING
#undef SQL_INVALID_HANDLE

#undef SQL_HANDLE_ENV
#undef SQL_HANDLE_SENV
#undef SQL_HANDLE_DBC
#undef SQL_HANDLE_STMT
#undef SQL_HANDLE_DESC

#undef SQL_ATTR_ODBC_VERSION
#undef SQL_ATTR_CONNECTION_POOLING
#undef SQL_ATTR_CP_MATCH
#undef SQL_ATTR_APPLICATION_KEY

#undef SQL_CP_OFF
#undef SQL_CP_ONE_PER_DRIVER
#undef SQL_CP_ONE_PER_HENV
#undef SQL_CP_DRIVER_AWARE
#undef SQL_CP_DEFAULT

#undef SQL_CP_STRICT_MATCH
#undef SQL_CP_RELAXED_MATCH
#undef SQL_CP_MATCH_DEFAULT

#undef SQL_OV_ODBC2
#undef SQL_OV_ODBC3
#undef SQL_OV_ODBC3_80

#undef SQL_ATTR_ACCESS_MODE
#undef SQL_ATTR_AUTOCOMMIT
#undef SQL_ATTR_CONNECTION_TIMEOUT
#undef SQL_ATTR_CURRENT_CATALOG
#undef SQL_ATTR_DISCONNECT_BEHAVIOR
#undef SQL_ATTR_ENLIST_IN_DTC
#undef SQL_ATTR_ENLIST_IN_XA
#undef SQL_ATTR_LOGIN_TIMEOUT
#undef SQL_ATTR_ODBC_CURSORS
#undef SQL_ATTR_PACKET_SIZE
#undef SQL_ATTR_QUIET_MODE
#undef SQL_ATTR_TRACE
#undef SQL_ATTR_TRACEFILE
#undef SQL_ATTR_TRANSLATE_LIB
#undef SQL_ATTR_TRANSLATE_OPTION
#undef SQL_ATTR_TXN_ISOLATION
#undef SQL_ATTR_CONNECTION_DEAD
#undef SQL_ATTR_ANSI_APP
#undef SQL_ATTR_RESET_CONNECTION
#undef SQL_ATTR_ASYNC_DBC_EVENT

#undef SQL_FETCH_NEXT
#undef SQL_FETCH_FIRST
#undef SQL_FETCH_LAST
#undef SQL_FETCH_PRIOR
#undef SQL_FETCH_ABSOLUTE
#undef SQL_FETCH_RELATIVE

#undef SQL_COMMIT
#undef SQL_ROLLBACK

#undef SQL_NULL_HENV
#undef SQL_NULL_HDBC
#undef SQL_NULL_HSTMT
#undef SQL_NULL_HDESC

#undef SQLGetDiagRec
#undef SQLDrivers
#undef SQLBrowseConnect

namespace sql
{
    export constexpr SQLHANDLE const
	SQL_NULL_HANDLE = local_SQL_NULL_HANDLE;

    export constexpr auto const
	SQL_NTS = local_SQL_NTS;

    export constexpr auto const
	SQL_SUCCESS		= local_SQL_SUCCESS,
	SQL_SUCCESS_WITH_INFO	= local_SQL_SUCCESS_WITH_INFO,
	SQL_NO_DATA		= local_SQL_NO_DATA,
	SQL_NEED_DATA		= local_SQL_NEED_DATA,
	SQL_ERROR		= local_SQL_ERROR,
	SQL_STILL_EXECUTING	= local_SQL_STILL_EXECUTING,
	SQL_INVALID_HANDLE	= local_SQL_INVALID_HANDLE;

    export constexpr auto const
	SQL_HANDLE_ENV	    = local_SQL_HANDLE_ENV,
	SQL_HANDLE_SENV	    = local_SQL_HANDLE_SENV,
	SQL_HANDLE_DBC	    = local_SQL_HANDLE_DBC,
	SQL_HANDLE_STMT	    = local_SQL_HANDLE_STMT,
	SQL_HANDLE_DESC	    = local_SQL_HANDLE_DESC;

    export constexpr auto const
	SQL_ATTR_ODBC_VERSION       = local_SQL_ATTR_ODBC_VERSION,
	SQL_ATTR_CONNECTION_POOLING = local_SQL_ATTR_CONNECTION_POOLING,
	SQL_ATTR_CP_MATCH           = local_SQL_ATTR_CP_MATCH,
	SQL_ATTR_APPLICATION_KEY    = local_SQL_ATTR_APPLICATION_KEY;

    export constexpr auto const
	SQL_CP_OFF             = local_SQL_CP_OFF,
	SQL_CP_ONE_PER_DRIVER  = local_SQL_CP_ONE_PER_DRIVER,
	SQL_CP_ONE_PER_HENV    = local_SQL_CP_ONE_PER_HENV,
	SQL_CP_DRIVER_AWARE    = local_SQL_CP_DRIVER_AWARE,
	SQL_CP_DEFAULT         = local_SQL_CP_DEFAULT;

    export constexpr auto const
	SQL_CP_STRICT_MATCH  = local_SQL_CP_STRICT_MATCH,
	SQL_CP_RELAXED_MATCH = local_SQL_CP_RELAXED_MATCH,
	SQL_CP_MATCH_DEFAULT = local_SQL_CP_MATCH_DEFAULT;

    export constexpr auto const
	SQL_OV_ODBC2	= local_SQL_OV_ODBC2,
	SQL_OV_ODBC3	= local_SQL_OV_ODBC3,
	SQL_OV_ODBC3_80 = local_SQL_OV_ODBC3_80;

    export constexpr auto const
	SQL_ATTR_ACCESS_MODE	     = local_SQL_ATTR_ACCESS_MODE,
	SQL_ATTR_AUTOCOMMIT	     = local_SQL_ATTR_AUTOCOMMIT,
	SQL_ATTR_CONNECTION_TIMEOUT  = local_SQL_ATTR_CONNECTION_TIMEOUT,
	SQL_ATTR_CURRENT_CATALOG     = local_SQL_ATTR_CURRENT_CATALOG,
	SQL_ATTR_DISCONNECT_BEHAVIOR = local_SQL_ATTR_DISCONNECT_BEHAVIOR,
	SQL_ATTR_ENLIST_IN_DTC	     = local_SQL_ATTR_ENLIST_IN_DTC,
	SQL_ATTR_ENLIST_IN_XA	     = local_SQL_ATTR_ENLIST_IN_XA,
	SQL_ATTR_LOGIN_TIMEOUT	     = local_SQL_ATTR_LOGIN_TIMEOUT,
	SQL_ATTR_ODBC_CURSORS	     = local_SQL_ATTR_ODBC_CURSORS,
	SQL_ATTR_PACKET_SIZE	     = local_SQL_ATTR_PACKET_SIZE,
	SQL_ATTR_QUIET_MODE	     = local_SQL_ATTR_QUIET_MODE,
	SQL_ATTR_TRACE		     = local_SQL_ATTR_TRACE,
	SQL_ATTR_TRACEFILE	     = local_SQL_ATTR_TRACEFILE,
	SQL_ATTR_TRANSLATE_LIB	     = local_SQL_ATTR_TRANSLATE_LIB,
	SQL_ATTR_TRANSLATE_OPTION    = local_SQL_ATTR_TRANSLATE_OPTION,
	SQL_ATTR_TXN_ISOLATION	     = local_SQL_ATTR_TXN_ISOLATION,
	SQL_ATTR_CONNECTION_DEAD     = local_SQL_ATTR_CONNECTION_DEAD,
	SQL_ATTR_ANSI_APP	     = local_SQL_ATTR_ANSI_APP,
	SQL_ATTR_RESET_CONNECTION    = local_SQL_ATTR_RESET_CONNECTION,
	SQL_ATTR_ASYNC_DBC_EVENT     = local_SQL_ATTR_ASYNC_DBC_EVENT;

    export constexpr auto const
	SQL_FETCH_NEXT      = local_SQL_FETCH_NEXT,
	SQL_FETCH_FIRST     = local_SQL_FETCH_FIRST,
	SQL_FETCH_LAST      = local_SQL_FETCH_LAST,
	SQL_FETCH_PRIOR     = local_SQL_FETCH_PRIOR,
	SQL_FETCH_ABSOLUTE  = local_SQL_FETCH_ABSOLUTE,
	SQL_FETCH_RELATIVE  = local_SQL_FETCH_RELATIVE;

    export constexpr auto const
	SQL_COMMIT	  = local_SQL_COMMIT,
	SQL_ROLLBACK      = local_SQL_ROLLBACK;

    export constexpr SQLHENV  const SQL_NULL_HENV      = local_SQL_NULL_HENV;
    export constexpr SQLHDBC  const SQL_NULL_HDBC      = local_SQL_NULL_HDBC;
    export constexpr SQLHSTMT const SQL_NULL_HSTMT     = local_SQL_NULL_HSTMT;
    export constexpr SQLHDESC const SQL_NULL_HDESC     = local_SQL_NULL_HDESC;

    export using ::SQLCHAR;
    export using ::SQLWCHAR;
    export using ::SQLTCHAR;
    export using ::SQLSMALLINT;
    export using ::SQLUSMALLINT;
    export using ::SQLINTEGER;
    export using ::SQLUINTEGER;
    export using ::SQLBIGINT;
    export using ::SQLUBIGINT;
    export using ::SQLLEN;
    export using ::SQLULEN;

    export using ::SQLSETPOSIROW;
    export using ::SQLROWCOUNT;
    export using ::SQLROWSETSIZE;
    export using ::SQLTRANSID;
    export using ::SQLROWOFFSET;

    export using ::SQLNUMERIC;
    export using ::SQLPOINTER;
    export using ::SQLREAL;
    export using ::SQLTIME;
    export using ::SQLTIMESTAMP;
    export using ::SQLVARCHAR;

    export using ::SQLHANDLE;
    export using ::SQLHENV;
    export using ::SQLHDBC;
    export using ::SQLHSTMT;
    export using ::SQLHDESC;
    export using ::SQLHWND;

    export using ::SQLRETURN;

    export using ::SQLGUID;
    export using ::SQL_YEAR_MONTH_STRUCT;
    export using ::SQL_DAY_SECOND_STRUCT;
    export using ::SQL_INTERVAL_STRUCT;
    export using ::SQL_DATE_STRUCT;
    export using ::SQL_TIME_STRUCT;
    export using ::SQL_TIMESTAMP_STRUCT;
    export using ::SQLINTERVAL;
    export using enum ::SQLINTERVAL;

    export using ::SQLAllocHandle;
    export using ::SQLFreeHandle;
    export using ::SQLGetDiagRecA;
    export using ::SQLGetDiagRecW;
    export using ::SQLSetEnvAttr;
    export using ::SQLDriversA;
    export using ::SQLDriversW;
    export using ::SQLBrowseConnectA;
    export using ::SQLBrowseConnectW;
    export using ::SQLDisconnect;

#if defined UNICODE || defined _UNICODE
    export constexpr auto const &SQLGetDiagRec	  = ::SQLGetDiagRecW;
    export constexpr auto const &SQLDrivers	  = ::SQLDriversW;
    export constexpr auto const &SQLBrowseConnect = ::SQLBrowseConnectW;
#else
    export constexpr auto const &SQLGetDiagRec	  = ::SQLGetDiagRecA;
    export constexpr auto const &SQLDrivers	  = ::SQLDriversA;
    export constexpr auto const &SQLBrowseConnect = ::SQLBrowseConnectA;
#endif
}
