cmake_minimum_required(VERSION 3.31)

# Set experimental flag to enable `import std` support from CMake.
# This must be enabled before C++ language support.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
    # This specific value changes as experimental support evolves. See
    # `Help/dev/experimental.rst` in the CMake source corresponding to
    # your CMake build for the exact value to use.
    "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(ODBC-Cmd VERSION 0.1 DESCRIPTION "Portable ODBC library and tools" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(SetupBoost)

set(ODBCXX_HEADERS
    "include/odbc++/Exports.h"
    "include/odbc++/SQLDiagnosticException.hh"
    "include/odbc++/Handle.hh"
    "include/odbc++/Environment.hh"
    "include/odbc++/Connection.hh"
    "include/odbc++/WindowsCategory.hh"
    "include/odbc++/FileStreamBuffer.hh"
    "include/odbc++/FileDescriptorDevice.hh"
    "include/odbc++/FileDescriptorSink.hh"
    "include/odbc++/FileDescriptorSource.hh"
    "include/odbc++/FileDescriptor.hh"
)

set(ODBCXX_SOURCES
    "src/odbc++/Handle.cc"
    "src/odbc++/Environment.cc"
    "src/odbc++/Connection.cc"
    "src/odbc++/WindowsCategory.cc"
    "src/odbc++/FileStreamBuffer.cc")

add_library(odbc++ SHARED ${ODBCXX_HEADERS} ${ODBCXX_SOURCES})
target_include_directories(odbc++ PUBLIC "include")
set_target_properties(odbc++
    PROPERTIES
	MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue"
	COMPILE_PDB_NAME "odbc++.compile"
	CXX_SCAN_FOR_MODULES ON
	INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

target_compile_features(odbc++ PUBLIC cxx_std_23)
target_link_libraries(odbc++ PUBLIC local_boost::iostreams)

if("23" IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    set_target_properties(odbc++ PROPERTIES CXX_MODULE_STD ON)
else()
    message(SEND_ERROR "C++ support for import std not implemented in the build system, see available compiler options")
endif()

if(WIN32)
    find_library(ODBC32_LIBRARY_PATH "ODBC32" REQUIRED)
    target_link_libraries(odbc++ PUBLIC "${ODBC32_LIBRARY_PATH}")
    target_compile_definitions(odbc++ PRIVATE WINDOWS)
endif()

set(SQLODBC_SOURCES
    "src/dbcmd/external/boost/iostreams.cc"
    "src/dbcmd/Context.cc"
    "src/dbcmd/CommandHandler.cc"
    "src/dbcmd/lib/HistoryList.cc"
    "src/dbcmd/lib/HistoryFile.cc"
    "src/dbcmd/lib/HistoryCache.cc"
    "src/dbcmd/browseConnect.cc"
    "src/dbcmd/Drivers.cc"
    "src/dbcmd/ShellCommand.cc"
    "src/dbcmd/ChDirCommand.cc"
    "src/dbcmd/EnvCommand.cc"
    "src/dbcmd/EchoCommand.cc"
    "src/dbcmd/HelpCommand.cc"
    "src/dbcmd/DiagnosticRecord.cc"
    "src/sqlodbc.cc")

add_executable(dbcmd)
target_sources(dbcmd PRIVATE FILE_SET CXX_MODULES FILES ${SQLODBC_SOURCES})
target_link_libraries(dbcmd PRIVATE odbc++) # boost_iostreams
target_compile_features(dbcmd PRIVATE cxx_std_23)

message(STATUS "CXX compiler import std: ${CMAKE_CXX_COMPILER_IMPORT_STD}")

if("23" IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    set_target_properties(dbcmd PROPERTIES CXX_MODULE_STD ON)
else()
    message(SEND_ERROR "C++ support for import std not implemented in the build system, see available compiler options")
endif()
    
set_target_properties(dbcmd
    PROPERTIES
	MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue"
	COMPILE_PDB_NAME "sqlodbc.compile"
	CXX_SCAN_FOR_MODULES ON
	INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

if(WIN32)
    find_library(SHELL32_LIBRARY_PATH "Shell32" REQUIRED)
    target_compile_definitions(dbcmd PRIVATE WINDOWS)
    target_link_libraries(dbcmd PRIVATE "${SHELL32_LIBRARY_PATH}")

    if(MSVC)
	target_include_directories(dbcmd PRIVATE "src/dbcmd")
    endif()
endif()
