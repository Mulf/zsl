add_executable(
	test_data_import_and_export
	test_data_import_and_export.cpp)
target_link_libraries(
	test_data_import_and_export
	GTest::gtest_main zsl
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")


add_executable(
	test_data_process
	test_data_process.cpp)
target_link_libraries(
	test_data_process
	GTest::gtest_main zsl
)

add_executable(
	test_descriptive_statistics
	test_descriptive_statistics.cpp)
target_link_libraries(
	test_descriptive_statistics
	GTest::gtest_main zsl
)
