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

export module winapi.WinDef;

namespace
{
    constexpr auto local_NULL = NULL;
    constexpr auto local_FALSE = FALSE, local_TRUE = TRUE;
}

#undef NULL
#undef FALSE
#undef TRUE

namespace winapi
{
    export constexpr auto NULL = nullptr; //  local_NULL;

    export constexpr auto FALSE = local_FALSE, TRUE = local_TRUE;

    export using ::BOOL;
    export using ::BYTE;
    export using ::WORD;
    export using ::DWORD;
 // export using ::QWORD;
    export using ::SIZE_T;

    export using ::CHAR;
    export using ::WCHAR;
    export using ::SHORT;
    export using ::INT;
    export using ::INT8;
    export using ::INT16;
    export using ::INT32;
    export using ::INT64;
    export using ::LONG;
    export using ::LONG32;
    export using ::LONG64;
    export using ::LONGLONG;

    export using ::UCHAR;
    export using ::USHORT;
    export using ::UINT;
    export using ::UINT8;
    export using ::UINT16;
    export using ::UINT32;
    export using ::UINT64;
    export using ::ULONG;
    export using ::ULONG32;
    export using ::ULONG64;
    export using ::ULONGLONG;

    export using ::DWORD32;
    export using ::DWORD64;
    export using ::DWORDLONG;
    export using ::DWORD_PTR;
    export using ::INT_PTR;
    export using ::LONG_PTR;
    export using ::ULONG_PTR;

    export using ::HANDLE;
    export using ::HANDLE64;
    export using ::HGLOBAL;
    export using ::HLOCAL;
    export using ::HRESULT;

    export using ::PVOID;
    export using ::PVOID64;
    export using ::PBOOL;
    export using ::PBYTE;
    export using ::PCHAR;
    export using ::PSTR;
    export using ::PWCHAR;
    export using ::PWSTR;
    export using ::PWORD;
    export using ::PDWORD;
    export using ::PDWORD32;
    export using ::PDWORD64;
    export using ::PDWORD32;
    export using ::PDWORD64;
    export using ::PDWORDLONG;
    export using ::PDWORD_PTR;
    export using ::PSHORT;
    export using ::PUSHORT;
    export using ::PINT;
    export using ::PINT8;
    export using ::PINT16;
    export using ::PINT32;
    export using ::PINT64;
    export using ::PUINT;
    export using ::PUINT8;
    export using ::PUINT16;
    export using ::PUINT32;
    export using ::PUINT64;
    export using ::PLONG;
    export using ::PLONG32;
    export using ::PLONG64;
    export using ::PLONG_PTR;
    export using ::PULONG;
    export using ::PULONG32;
    export using ::PULONG64;
    export using ::PULONG_PTR;

    export using ::PHANDLE;
    export using ::PHANDLE64;

    export using ::LPVOID;
    export using ::LPBOOL;
    export using ::LPBYTE;
    export using ::LPSTR;
    export using ::LPWSTR;
    export using ::LPWORD;
    export using ::LPDWORD;
    export using ::LPINT;
    export using ::LPLONG;

    export using ::LPHANDLE;

    export using ::LPCVOID;
    export using ::LPCCH;
    export using ::LPCWCH;
    export using ::LPCSTR;
    export using ::LPCWSTR;

    export using ::HWND;
    export using ::HDC;
    export using ::HBRUSH;
    export using ::HBITMAP;
    export using ::HMENU;
    export using ::HPALETTE;
    export using ::HFONT;
    export using ::HICON;
    export using ::HRGN;
    export using ::HKEY;
    export using ::HFILE;
    export using ::HLOCAL;
    export using ::HGLOBAL;

    export using ::RECT;
    export using ::POINT;
    export using ::WPARAM;
    export using ::LPARAM;
    export using ::LRESULT;

    export using ::FILETIME;
    export using ::PFILETIME;
    export using ::LPFILETIME;

    export using ::PROC;
    export using ::NEARPROC;
    export using ::FARPROC;
}
