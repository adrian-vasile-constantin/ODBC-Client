include_guard(GLOBAL)

find_package(Git)

set(LOCAL_BOOST_LIBRARY_LIST
	"config"
	"throw_exception"
	"assert"
	"preprocessor"
	"static_assert"
	"type_traits"
	"core"
	"integer"
	"utility"
	"smart_ptr"
	"mpl"
	"range"
	"iterator"
	"detail"
	"concept_check"
	"move"
	"intrusive")

if (Git_FOUND)
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/CMakeLists.txt")
	execute_process(COMMAND "${GIT_EXECUTABLE}" "submodule" "update" "--init" "libs/boost"
	    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	    COMMAND_ECHO STDOUT COMMAND_ERROR_IS_FATAL ANY)
    endif()

    set(LOCAL_BOOST_LIBRARIES)

    foreach(LIBNAME IN LISTS LOCAL_BOOST_LIBRARY_LIST)
	if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/libs/${LIBNAME}/include/boost")
	    list(APPEND LOCAL_BOOST_LIBRARIES "libs/${LIBNAME}")
	endif()
    endforeach()

    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/libs/iostreams/include/boost/iostreams/stream_buffer.hpp")
	list(APPEND LOCAL_BOOST_LIBRARIES "libs/iostreams")
    endif()

    if(LOCAL_BOOST_LIBRARIES)
	execute_process(COMMAND "${GIT_EXECUTABLE}" "-C" "libs/boost" "submodule" "update" "--init" ${LOCAL_BOOST_LIBRARIES}
	    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	    COMMAND_ECHO STDOUT COMMAND_ERROR_IS_FATAL ANY)
    endif()
endif()

function(add_boost_interface_library LIBRARY_NAME)
    add_library(local_boost_${LIBRARY_NAME} INTERFACE)
    target_include_directories(local_boost_${LIBRARY_NAME} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/libs/${LIBRARY_NAME}/include>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/odbc++>")
    add_library(local_boost::${LIBRARY_NAME} ALIAS local_boost_${LIBRARY_NAME})
    list(APPEND LOCAL_BOOST_DEPENDENCY_LIBS local_boost::${LIBRARY_NAME})
    set(LOCAL_BOOST_DEPENDENCY_LIBS "${LOCAL_BOOST_DEPENDENCY_LIBS}" PARENT_SCOPE)
endfunction()

function(install_boost_interface_library LIBRARY_NAME)
    install(DIRECTORY "libs/boost/libs/${LIBRARY_NAME}/include/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/odbc++" COMPONENT Development)
    install(TARGETS local_boost_${LIBRARY_NAME} EXPORT "odbc++-local_boost")
endfunction()

foreach(LIBRARY_NAME IN LISTS LOCAL_BOOST_LIBRARY_LIST)
    add_boost_interface_library("${LIBRARY_NAME}")
    install_boost_interface_library("${LIBRARY_NAME}")
endforeach()

set(LOCAL_BOOST_IOSTREAMS_DEPENDENCY_LIBS "${LOCAL_BOOST_DEPENDENCY_LIBS}")

add_boost_interface_library("iostreams")
install_boost_interface_library("iostreams")

target_compile_definitions(local_boost_iostreams INTERFACE "BOOST_ALL_NO_LIB")
target_sources(local_boost_iostreams INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/boost/libs/iostreams/src/file_descriptor.cpp>")
target_link_libraries(local_boost_iostreams INTERFACE ${LOCAL_BOOST_IOSTREAMS_DEPENDENCY_LIBS})

install(EXPORT "odbc++-local_boost" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake" COMPONENT Development)
