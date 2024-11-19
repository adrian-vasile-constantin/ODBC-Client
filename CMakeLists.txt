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
set(CMAKE_INSTALL_MESSAGE LAZY)

include(cmake/LocalModulePath.cmake)
include(SetupBoost)

include(odbc++.cmake)
include(dbcmd.cmake)
