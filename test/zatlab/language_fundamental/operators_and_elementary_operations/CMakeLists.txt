add_executable(
	test_arithmetic_operations 
	test_arithmetic_operations.cpp
)

target_link_libraries(
	test_arithmetic_operations
	GTest::gtest_main zsl
)

