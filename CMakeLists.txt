cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)

project(proj_stub)

add_library(stub src/hello.cpp)
target_sources(stub
  PUBLIC
  FILE_SET HEADERS
  BASE_DIRS src
  FILES
  src/hello.hpp)

target_include_directories(stub PUBLIC src)

add_executable(main src/main.cpp)
target_link_libraries(main stub)

include(CTest)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

option(BUILD_BENCHMARKING "build benchmarks" ON)
if(BUILD_BENCHMARKING)
  add_subdirectory(benchmark)
endif()
