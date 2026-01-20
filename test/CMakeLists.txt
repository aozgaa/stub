set(DATA_DIR ${CMAKE_CURRENT_LIST_DIR}/integration)

add_test(
  NAME integration_empty
  COMMAND ${CMAKE_COMMAND}
    "-DAPP_EXE=$<TARGET_FILE:main>"
    "-DINPUT_FILE=${DATA_DIR}/empty.in"
    "-DEXPECTED_FILE=${DATA_DIR}/empty.out"
    "-DOUTPUT_FILE=${CMAKE_CURRENT_BINARY_DIR}/integration_empty-actual.txt"
    -P "${CMAKE_CURRENT_LIST_DIR}/scripts/run_and_compare.cmake"
)

add_executable(unit_stub unit_stub.cpp)
target_link_libraries(unit_stub stub)

target_include_directories(unit_stub PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(
  NAME unit_stub
  COMMAND unit_stub
)
