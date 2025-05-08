add_executable(
	test_matrices_and_arrays
	test_matrices_and_arrays.cpp
)

target_link_libraries(
	test_matrices_and_arrays
	GTest::gtest_main zsl
)

add_subdirectory(language_fundamental)
add_subdirectory(data_import_and_analysis)