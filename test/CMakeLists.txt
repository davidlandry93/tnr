
enable_testing()
find_package(GTest)

include_directories(${GTEST_INCLUDE_DIRS} ${TNR_INCLUDE_DIRS})

file(GLOB TEST_FILES *.cpp)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests tnr ${GTEST_BOTH_LIBRARIES} pthread)
target_include_directories(tests PRIVATE $<TARGET_PROPERTY:tnr,INCLUDE_DIRECTORIES>)

file(COPY "teachrepeat.json" DESTINATION "${CMAKE_BINARY_DIR}/test")

add_test(NAME tnr_tests COMMAND tests)
