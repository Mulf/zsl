
add_executable(
	test_rand
	test_rand.cpp
)
target_link_libraries(
	test_rand
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

# fourier analysis and filtering
add_executable(
	test_fourier_analysis_and_filtering
	test_fourier_analysis_and_filtering.cpp
)
target_link_libraries(
	test_fourier_analysis_and_filtering
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

# interpolation
add_executable(
	test_interpolation
	test_interpolation.cpp
)
target_link_libraries(
	test_interpolation
	GTest::gtest_main zsl matplot
)
add_compile_definitions("CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(elementary_math)
