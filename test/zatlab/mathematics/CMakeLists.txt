add_executable(
	test_elementary_math
	test_elementary_math.cpp
)
target_link_libraries(
	test_elementary_math
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(
	test_rand
	test_rand.cpp
)
target_link_libraries(
	test_rand
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(
	test_fourier_analysis_and_filtering
	test_fourier_analysis_and_filtering.cpp
)
target_link_libraries(
	test_fourier_analysis_and_filtering
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

