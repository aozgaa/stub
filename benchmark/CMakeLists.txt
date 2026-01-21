add_subdirectory(${CMAKE_SOURCE_DIR}/ext/nanobench ${CMAKE_CURRENT_BINARY_DIR}/nanobench)

add_executable(benchmain main.cpp)
target_link_libraries(benchmain PRIVATE nanobench stub)
