module;

#include <ShlObj.h>

export module winapi.ShlObj;

#if !defined __INTELLISENSE__
import winapi.KnownFolders;
#endif

namespace winapi
{
    export using ::KNOWN_FOLDER_FLAG;
    export using enum ::KNOWN_FOLDER_FLAG;

    export using ::SHGetKnownFolderPath;
}
