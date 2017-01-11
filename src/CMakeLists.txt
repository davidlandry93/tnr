
include_directories(.)

set(SOURCES anchor_point.cpp)
add_library(tnr ${SOURCES})
target_link_libraries(tnr)

set(PUBLIC_HEADERS anchor_point.h)

INSTALL(FILES ${PUBLIC_HEADERS} DESTINATION ${INSTALL_INCLUDE_DIR})
INSTALL(TARGETS tnr DESTINATION ${INSTALL_LIB_DIR} EXPORT tnr-targets)

export(EXPORT tnr-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/tnr/tnr-targets.cmake)
INSTALL(EXPORT tnr-targets DESTINATION ${INSTALL_CMAKE_DIR})
