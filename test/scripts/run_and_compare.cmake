execute_process(
  COMMAND "${APP_EXE}"
  INPUT_FILE "${INPUT_FILE}"
  OUTPUT_FILE "${OUTPUT_FILE}"
  RESULT_VARIABLE cmd_result
)

if(NOT cmd_result EQUAL 0)
  message(FATAL_ERROR "Command failed with exit code ${cmd_result}")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E compare_files "${OUTPUT_FILE}" "${EXPECTED_FILE}"
  RESULT_VARIABLE compare_result
)

if(NOT compare_result EQUAL 0)
  message(FATAL_ERROR "Output did not match expected")
endif()
