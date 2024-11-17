cmake_minimum_required(VERSION 3.26)

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
    # "include/odbc++/FileStreamBuffer.hh"
    # "include/odbc++/FileDescriptorDevice.hh"
    # "include/odbc++/FileDescriptorSink.hh"
    # "include/odbc++/FileDescriptorSource.hh"
    # "include/odbc++/FileDescriptor.hh"
)

set(ODBCXX_SOURCES
    "src/odbc++/Handle.cc"
    "src/odbc++/Environment.cc"
    "src/odbc++/Connection.cc"
    "src/odbc++/WindowsCategory.cc"
    "src/odbc++/FileStreamBuffer.cc")

add_library(odbc++ SHARED ${ODBCXX_HEADERS} ${ODBCXX_SOURCES})
target_include_directories(odbc++ PUBLIC "include")
set_target_properties(odbc++ PROPERTIES MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue" COMPILE_PDB_NAME "odbc++.compile")
target_compile_features(odbc++ PUBLIC cxx_std_23)
target_link_libraries(odbc++ PUBLIC local_boost::iostreams)

if(WIN32)
    target_link_libraries(odbc++ PUBLIC ODBC32)
endif()

set(SQLODBC_HEADERS
    "src/dbcmd/Context.hh"
    "src/dbcmd/CommandHandler.hh"
    "src/dbcmd/HandlerFunctor.hh"
    "src/dbcmd/browseConnect.hh"
    "src/dbcmd/Drivers.hh"
    "src/dbcmd/ShellCommand.hh"
    "src/dbcmd/ChDirCommand.hh"
    "src/dbcmd/EnvCommand.hh"
    "src/dbcmd/EchoCommand.hh"
    "src/dbcmd/HelpCommand.hh"
    "src/dbcmd/DiagnosticRecord.hh"
    "src/dbcmd/lib/HistoryFile.hh")

set(SQLODBC_SOURCES
    "src/sqlodbc.cc"
    "src/dbcmd/Context.cc"
    "src/dbcmd/CommandHandler.cc"
    "src/dbcmd/browseConnect.cc"
    "src/dbcmd/Drivers.cc"
    "src/dbcmd/ShellCommand.cc"
    "src/dbcmd/ChDirCommand.cc"
    "src/dbcmd/EnvCommand.cc"
    "src/dbcmd/EchoCommand.cc"
    "src/dbcmd/HelpCommand.cc"
    "src/dbcmd/DiagnosticRecord.cc"
    "src/dbcmd/lib/HistoryFile.cc")

add_executable(dbcmd ${SQLODBC_HEADERS} ${SQLODBC_SOURCES})
target_link_libraries(dbcmd PRIVATE odbc++) # boost_iostreams
target_compile_features(dbcmd PRIVATE cxx_std_23)
set_target_properties(dbcmd PROPERTIES MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue" COMPILE_PDB_NAME "sqlodbc.compile")

if(WIN32)
    find_library(SHELL32_LIBRARY_PATH "Shell32" REQUIRED)
    target_compile_definitions(dbcmd PRIVATE WINDOWS)
    target_link_libraries(dbcmd PRIVATE "${SHELL32_LIBRARY_PATH}")
endif()
