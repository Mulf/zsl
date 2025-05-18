add_executable(
	test_constants_and_test_matrices
	test_constants_and_test_matrices.cpp
)
target_link_libraries(
	test_constants_and_test_matrices
	PUBLIC  zsl GTest::gtest_main
)