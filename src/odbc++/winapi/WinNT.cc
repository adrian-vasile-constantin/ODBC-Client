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
    constexpr DWORD
	local_GENERIC_ALL	= GENERIC_ALL,
	local_GENERIC_EXECUTE	= GENERIC_EXECUTE,
	local_GENERIC_WRITE	= GENERIC_WRITE,
	local_GENERIC_READ	= GENERIC_READ;

    constexpr DWORD
	local_FILE_GENERIC_EXECUTE	= FILE_GENERIC_EXECUTE,

	local_FILE_EXECUTE		= FILE_EXECUTE,
	local_FILE_READ_ATTRIBUTES	= FILE_READ_ATTRIBUTES,
	local_STANDARD_RIGHTS_EXECUTE	= STANDARD_RIGHTS_EXECUTE,
	local_SYNCHRONIZE		= SYNCHRONIZE,

	local_FILE_GENERIC_READ		= FILE_GENERIC_READ,

	local_FILE_READ_DATA		= FILE_READ_DATA,
	local_FILE_READ_EA		= FILE_READ_EA,
	local_STANDARD_RIGHTS_READ	= STANDARD_RIGHTS_READ,

	local_FILE_GENERIC_WRITE	= FILE_GENERIC_WRITE,

	local_FILE_APPEND_DATA		= FILE_APPEND_DATA,
	local_FILE_WRITE_ATTRIBUTES	= FILE_WRITE_ATTRIBUTES,
	local_FILE_WRITE_DATA		= FILE_WRITE_DATA,
	local_FILE_WRITE_EA		= FILE_WRITE_EA,
	local_STANDARD_RIGHTS_WRITE	= STANDARD_RIGHTS_WRITE,

	local_FILE_ADD_FILE              = FILE_ADD_FILE,
	local_FILE_ADD_SUBDIRECTORY	 = FILE_ADD_SUBDIRECTORY,
	local_FILE_ALL_ACCESS		 = FILE_ALL_ACCESS,
	local_FILE_CREATE_PIPE_INSTANCE	 = FILE_CREATE_PIPE_INSTANCE,
	local_FILE_DELETE_CHILD		 = FILE_DELETE_CHILD,
	local_FILE_LIST_DIRECTORY	 = FILE_LIST_DIRECTORY,
	local_FILE_TRAVERSE		 = FILE_TRAVERSE,

	local_DELETE			 = DELETE,
	local_READ_CONTROL		 = READ_CONTROL,
	local_WRITE_DAC			 = WRITE_DAC,
	local_WRITE_OWNER		 = WRITE_OWNER,
	local_STANDARD_RIGHTS_REQUIRED	 = STANDARD_RIGHTS_REQUIRED,
	local_STANDARD_RIGHTS_ALL	 = STANDARD_RIGHTS_ALL,
	local_SPECIFIC_RIGHTS_ALL	 = SPECIFIC_RIGHTS_ALL,
	local_ACCESS_SYSTEM_SECURITY	 = ACCESS_SYSTEM_SECURITY,
	local_MAXIMUM_ALLOWED		 = MAXIMUM_ALLOWED;


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
}

#undef GENERIC_ALL
#undef GENERIC_EXECUTE
#undef GENERIC_WRITE
#undef GENERIC_READ

#undef FILE_GENERIC_EXECUTE

#undef FILE_EXECUTE
#undef FILE_READ_ATTRIBUTES
#undef STANDARD_RIGHTS_EXECUTE
#undef SYNCHRONIZE

#undef FILE_GENERIC_READ

#undef FILE_READ_DATA
#undef FILE_READ_EA
#undef STANDARD_RIGHTS_READ

#undef FILE_GENERIC_WRITE

#undef FILE_APPEND_DATA
#undef FILE_WRITE_ATTRIBUTES
#undef FILE_WRITE_DATA
#undef FILE_WRITE_EA
#undef STANDARD_RIGHTS_WRITE

#undef FILE_ADD_FILE
#undef FILE_ADD_SUBDIRECTORY
#undef FILE_ALL_ACCESS
#undef FILE_CREATE_PIPE_INSTANCE
#undef FILE_DELETE_CHILD
#undef FILE_LIST_DIRECTORY
#undef FILE_TRAVERSE

#undef DELETE
#undef READ_CONTROL
#undef WRITE_DAC
#undef WRITE_OWNER
#undef STANDARD_RIGHTS_REQUIRED
#undef STANDARD_RIGHTS_ALL
#undef SPECIFIC_RIGHTS_ALL
#undef ACCESS_SYSTEM_SECURITY
#undef MAXIMUM_ALLOWED

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

    export constexpr auto
	GENERIC_ALL		    = local_GENERIC_ALL,
	GENERIC_EXECUTE		    = local_GENERIC_EXECUTE,
	GENERIC_WRITE		    = local_GENERIC_WRITE,
	GENERIC_READ		    = local_GENERIC_READ;

    export constexpr auto
	FILE_GENERIC_EXECUTE	    = local_FILE_GENERIC_EXECUTE,

	FILE_EXECUTE		    = local_FILE_EXECUTE,
	FILE_READ_ATTRIBUTES	    = local_FILE_READ_ATTRIBUTES,
	STANDARD_RIGHTS_EXECUTE	    = local_STANDARD_RIGHTS_EXECUTE,
	SYNCHRONIZE		    = local_SYNCHRONIZE,

	FILE_GENERIC_READ	    = local_FILE_GENERIC_READ,

	FILE_READ_DATA		    = local_FILE_READ_DATA,
	FILE_READ_EA		    = local_FILE_READ_EA,
	STANDARD_RIGHTS_READ	    = local_STANDARD_RIGHTS_READ,

	FILE_GENERIC_WRITE	    = local_FILE_GENERIC_WRITE,

	FILE_APPEND_DATA	    = local_FILE_APPEND_DATA,
	FILE_WRITE_ATTRIBUTES	    = local_FILE_WRITE_ATTRIBUTES,
	FILE_WRITE_DATA		    = local_FILE_WRITE_DATA,
	FILE_WRITE_EA		    = local_FILE_WRITE_EA,
	STANDARD_RIGHTS_WRITE	    = local_STANDARD_RIGHTS_WRITE,

	FILE_ADD_FILE		    = local_FILE_ADD_FILE,
	FILE_ADD_SUBDIRECTORY	    = local_FILE_ADD_SUBDIRECTORY,
	FILE_ALL_ACCESS		    = local_FILE_ALL_ACCESS,
	FILE_CREATE_PIPE_INSTANCE   = local_FILE_CREATE_PIPE_INSTANCE,
	FILE_DELETE_CHILD	    = local_FILE_DELETE_CHILD,
	FILE_LIST_DIRECTORY	    = local_FILE_LIST_DIRECTORY,
	FILE_TRAVERSE		    = local_FILE_TRAVERSE,
    
	DELETE			    = local_DELETE,
	READ_CONTROL		    = local_READ_CONTROL,
	WRITE_DAC		    = local_WRITE_DAC,
	WRITE_OWNER		    = local_WRITE_OWNER,
	STANDARD_RIGHTS_REQUIRED    = local_STANDARD_RIGHTS_REQUIRED,
	STANDARD_RIGHTS_ALL	    = local_STANDARD_RIGHTS_ALL,
	SPECIFIC_RIGHTS_ALL	    = local_SPECIFIC_RIGHTS_ALL,
	ACCESS_SYSTEM_SECURITY	    = local_ACCESS_SYSTEM_SECURITY,
	MAXIMUM_ALLOWED		    = local_MAXIMUM_ALLOWED;

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

    export using ::LARGE_INTEGER;
    export using ::PLARGE_INTEGER;
    export using ::ACCESS_MASK;
    export using ::PACCESS_MASK;
}
