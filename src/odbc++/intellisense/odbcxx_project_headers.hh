#if !defined SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
#define SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED

#if defined __INTELLISENSE__

// For MS IntelliSense only

# define MSVC_INTELLISENSE 1

#if defined WINDOWS

# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif

# include <windef.h>
# include <winbase.h>
# include <errhandlingapi.h>
# include <winerror.h>
# include <objbase.h>
# include <fileapi.h>
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
#include <ios>
#include <filesystem>
#include <limits>

#include <boost/iostreams/device/file_descriptor.hpp>

#include <sql.h>
#include <sqlext.h>
#include <sqlucode.h>

#include "ODBCXX_Export.h"

#include "Handle.hh"
#include "SQLDiagnosticException.hh"
#include "Connection.hh"
#include "Environment.hh"
#include "WindowsCategory.hh"

#include "FileDescriptorDevice.hh"
#include "FileDescriptorSink.hh"
#include "FileDescriptorSource.hh"

namespace ext
{
    namespace boost = ::boost;
}

#endif	    // defined __INTELLISENSE__

#endif	    // !defined SQL_ODBCXX_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
