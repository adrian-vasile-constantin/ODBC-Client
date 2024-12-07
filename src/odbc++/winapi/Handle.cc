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
#include <handleapi.h>

export module winapi.Handle;

#if !defined __INTELLISENSE__
import winapi.WinDef;

using winapi::HANDLE;
using winapi::LONG_PTR;
#endif

namespace
{
    auto const local_INVALID_HANDLE_VALUE = INVALID_HANDLE_VALUE;    // C2131: expression did not evaluate to a constant
									    // note:  failure was caused by unevaluable pointer value

    constexpr auto
	local_DUPLICATE_CLOSE_SOURCE = DUPLICATE_CLOSE_SOURCE,
	local_DUPLICATE_SAME_ACCESS  = DUPLICATE_SAME_ACCESS;
}

#undef INVALID_HANDLE_VALUE
#undef DUPLICATE_CLOSE_SOURCE
#undef DUPLICATE_SAME_ACCESS

namespace winapi
{
    export auto const INVALID_HANDLE_VALUE = local_INVALID_HANDLE_VALUE;

    export constexpr auto
	DUPLICATE_CLOSE_SOURCE = local_DUPLICATE_CLOSE_SOURCE,
	DUPLICATE_SAME_ACCESS  = local_DUPLICATE_SAME_ACCESS;

    export using ::DuplicateHandle;
    export using ::CloseHandle;
}
