
message(STATUS ${EXTERNAL_DIR})

set(SOURCES
  anchor_point.cpp
  pointcloud.cpp
  pose.cpp
  teach_and_repeat_map.cpp)
add_library(tnr ${SOURCES})
target_link_libraries(tnr jsoncpp)

add_executable(tnr_csv2json csv2json.cpp)
target_link_libraries(tnr_csv2json tnr gflags)

set(PUBLIC_HEADERS
  anchor_point.h
  pointcloud.h
  pose.h
  quaternion.h
  teach_and_repeat_map.h
  vector3.h)

INSTALL(TARGETS tnr DESTINATION ${INSTALL_LIB_DIR} EXPORT tnr-targets)
INSTALL(FILES ${PUBLIC_HEADERS} DESTINATION ${INSTALL_INCLUDE_DIR})
export(EXPORT tnr-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/../tnr-targets.cmake)
INSTALL(EXPORT tnr-targets DESTINATION ${INSTALL_CMAKE_DIR})
