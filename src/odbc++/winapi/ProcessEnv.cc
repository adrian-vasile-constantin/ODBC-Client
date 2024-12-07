module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include <windef.h>
#include <processenv.h>

export module winapi.ProcessEnv;

#if !defined __INTELLISENSE__
import winapi.WinDef;
#endif

#undef FreeEnvironmentStrings

namespace winapi
{
    export using ::GetEnvironmentStrings;
    export using ::FreeEnvironmentStringsA;
    export using ::FreeEnvironmentStringsW;

#if defined _UNICODE || defined UNICODE
    export constexpr auto &FreeEnvironmentStrings = ::FreeEnvironmentStringsW;
#else
    export constexpr auto &FreeEnvironmentStrings = ::FreeEnvironmentStringsA;
#endif
}
