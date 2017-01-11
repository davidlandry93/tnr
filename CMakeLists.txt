
cmake_minimum_required(VERSION 3.0)
project(TNR)

set(INSTALL_LIB_DIR lib)
set(INSTALL_INCLUDE_DIR include/tnr)
set(INSTALL_CMAKE_DIR lib/cmake/tnr)

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
