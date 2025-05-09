add_executable(
	test_elementary_math
	test_elementary_math.cpp
)

target_link_libraries(
	test_elementary_math
	GTest::gtest_main zsl matplot
)


add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")