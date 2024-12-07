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
#include <winnt.h>

export module winapi.WinNT;

namespace
{
    inline auto local_MAKELANGID(WORD primary_lang_id, WORD secondary_lang_id) -> decltype(MAKELANGID(primary_lang_id, secondary_lang_id))
    {
	return MAKELANGID(primary_lang_id, secondary_lang_id);
    }

    inline auto local_PRIMARYLANGID(WORD lgid) -> decltype(PRIMARYLANGID(lgid))
    {
	return PRIMARYLANGID(lgid);
    }

    inline auto local_SUBLANGID(WORD lgid) -> decltype(SUBLANGID(lgid))
    {
	return SUBLANGID(lgid);
    }

    constexpr auto const
	local_LANG_NEUTRAL	= LANG_NEUTRAL,
	local_LANG_INVARIANT	= LANG_INVARIANT;

    constexpr auto const
	local_SUBLANG_NEUTRAL		    = SUBLANG_NEUTRAL,
	local_SUBLANG_DEFAULT		    = SUBLANG_DEFAULT,
	local_SUBLANG_SYS_DEFAULT	    = SUBLANG_SYS_DEFAULT,
	local_SUBLANG_CUSTOM_DEFAULT	    = SUBLANG_CUSTOM_DEFAULT,
	local_SUBLANG_CUSTOM_UNSPECIFIED    = SUBLANG_CUSTOM_UNSPECIFIED,
	local_SUBLANG_UI_CUSTOM_DEFAULT	    = SUBLANG_UI_CUSTOM_DEFAULT;
}

#undef MAKELANGID
#undef PRIMARYLANGID
#undef SUBLANGID

#undef LANG_NEUTRAL
#undef LANG_INVARIANT

#undef SUBLANG_NEUTRAL
#undef SUBLANG_DEFAULT
#undef SUBLANG_SYS_DEFAULT
#undef SUBLANG_CUSTOM_DEFAULT
#undef SUBLANG_CUSTOM_UNSPECIFIED
#undef SUBLANG_UI_CUSTOM_DEFAULT

namespace winapi
{
    export inline auto MAKELANGID(WORD primary, WORD secondary) -> decltype(local_MAKELANGID(primary, secondary))
    {
	return local_MAKELANGID(primary, secondary);
    }

    export inline auto PRIMARYLANGID(WORD lgid) -> decltype(local_PRIMARYLANGID(lgid))
    {
	return local_PRIMARYLANGID(lgid);
    }

    export inline auto SUBLANGID(WORD lgid) -> decltype(local_SUBLANGID(lgid))
    {
	return local_SUBLANGID(lgid);
    }

    export constexpr auto const
	LANG_NEUTRAL	= local_LANG_NEUTRAL,
	LANG_INVARIANT	= local_LANG_INVARIANT;

    export constexpr auto const
	SUBLANG_NEUTRAL		    = local_SUBLANG_NEUTRAL,
	SUBLANG_DEFAULT		    = local_SUBLANG_DEFAULT,
	SUBLANG_SYS_DEFAULT	    = local_SUBLANG_SYS_DEFAULT,
	SUBLANG_CUSTOM_DEFAULT	    = local_SUBLANG_CUSTOM_DEFAULT,
	SUBLANG_CUSTOM_UNSPECIFIED  = local_SUBLANG_CUSTOM_UNSPECIFIED,
	SUBLANG_UI_CUSTOM_DEFAULT   = local_SUBLANG_UI_CUSTOM_DEFAULT;
}
