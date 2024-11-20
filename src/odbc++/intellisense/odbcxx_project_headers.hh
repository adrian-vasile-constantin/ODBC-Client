#if !defined SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
#define SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED

#if defined __INTELLISENSE__

// For MS IntelliSense only

# define MSVC_INTELLISENSE 1

#if defined WINDOWS
# include <windef.h>
# include <windef.h>
# include <errhandlingapi.h>
# include <winerror.h>
#endif

#include <cstddef>
#include <cerrno>

#include <type_traits>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <span>
#include <tuple>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <execution>
#include <exception>
#include <stdexcept>
#include <system_error>

#include <sql.h>
#include <sqlext.h>
#include <sqlucode.h>

#include "ODBCXX_Export.h"

#include "Handle.hh"
#include "SQLDiagnosticException.hh"
#include "Connection.hh"
#include "Environment.hh"
#include "WindowsCategory.hh"

#endif	    // defined __INTELLISENSE__

#endif	    // !defined SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
