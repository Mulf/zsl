add_executable(
	test_matrices_and_arrays
	test_matrices_and_arrays.cpp
)

target_link_libraries(
	test_matrices_and_arrays
	GTest::gtest_main zsl
)