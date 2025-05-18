add_executable(
	test_constants_and_test_matrices
	test_constants_and_test_matrices.cpp)
target_link_libraries(
	test_constants_and_test_matrices
	PUBLIC  zsl GTest::gtest_main
)

add_executable(
	test_trigonometry
	test_trigonometry.cpp)
target_link_libraries(
	test_trigonometry
	PUBLIC  GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")