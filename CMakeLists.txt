
cmake_minimum_required(VERSION 3.1)
project(TNR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(INSTALL_LIB_DIR lib)
set(INSTALL_INCLUDE_DIR include/tnr)
set(INSTALL_CMAKE_DIR lib/cmake/tnr)

set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

include_directories(src ${EXTERNAL_DIR}/jsoncpp/include)

add_subdirectory(${EXTERNAL_DIR}/jsoncpp)
add_subdirectory(src)

export(PACKAGE tnr)

foreach(p LIB INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
set(CONF_INCLUDE_DIRS "\${TNR_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(tnr-config.cmake.in ${PROJECT_BINARY_DIR}/tnr-config.cmake @ONLY)
INSTALL(FILES ${PROJECT_BINARY_DIR}/tnr-config.cmake DESTINATION ${INSTALL_CMAKE_DIR})

option(tests "Generate tests." ON) # Turn off with -Dtests=OFF

if(tests)
  add_subdirectory(${EXTERNAL_DIR}/googletest)
  add_subdirectory(test)
endif(tests)
