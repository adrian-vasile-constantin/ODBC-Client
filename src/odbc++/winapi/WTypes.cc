module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include <wtypes.h>

export module winapi.WTypes;

namespace winapi
{
    export using ::SCODE;
    export using ::BLOB;

    export using ::CLSCTX;
    export using ::MSHCTX;
    export using ::MSHLFLAGS;

    export using ::CSPLATFORM;
    export using ::CY;
    export using ::DECIMAL;
    export using ::PROPERTYKEY;
    export using ::QUERYCONTEXT;
    export using ::DVASPECT;
    export using ::STATFLAG;
    export using ::STGC;
    export using ::STGMOVE;
    export using ::TYSPEC;
    export using ::VARENUM;

    export using ::SECURITY_ATTRIBUTES;
    export using ::PSECURITY_ATTRIBUTES;
    export using ::LPSECURITY_ATTRIBUTES;
}
