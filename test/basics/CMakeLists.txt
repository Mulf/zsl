add_executable(
	test_check
	test_check.cpp
 )

 target_link_libraries(
	test_check
	GTest::gtest_main zsl
)
