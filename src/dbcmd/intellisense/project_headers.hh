#if !defined DBCMD_INTELLISENSE_HEADERS_HH_INCLUDED
#define DBCMD_INTELLISENSE_HEADERS_HH_INCLUDED

#if defined __INTELLISENSE__

#define MSVC_INTELLISENSE 1

#if defined WINDOWS
# include <windef.h>
# include <WinBase.h>
# include <ShlObj.h>
#endif

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#include <initializer_list>
#include <limits>
#include <utility>
#include <tuple>
#include <memory>
#include <string>
#include <string_view>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <iterator>
#include <ranges>
#include <algorithm>
#include <execution>
#include <array>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <ios>
#include <streambuf>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>

#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filter/newline.hpp>

#include <boost/intrusive/any_hook.hpp>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>
#include <boost/intrusive/parent_from_member.hpp>


#include <../odbc++/intellisense/odbcxx_project_headers.hh>

#include "HistoryUniqueList.hh"
#include "HistoryMultiList.hh"
#include "HistoryFile.hh"
#include "HistoryCache.hh"

#include "Context.hh"
#include "CommandHandler.hh"

#include "browseConnect.hh"
#include "DiagnosticRecord.hh"
#include "ChDirCommand.hh"
#include "DriversCommand.hh"
#include "EchoCommand.hh"
#include "HelpCommand.hh"
#include "ShellCommand.hh"

#endif

#endif	    // ! defined DBCMD_INTELLISENSE_HEADERS_HH_INCLUDED
