add_executable(
	std_vector_op
	std_vector_op.cpp
)

target_link_libraries(
	std_vector_op
	GTest::gtest_main zsl
)

