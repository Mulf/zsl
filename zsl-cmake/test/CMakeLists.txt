include(FetchContent)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
	test_std_vector_op
	test_std_vector_op.cpp
 "zatlab/test_matrices_and_arrays.cpp")

target_link_libraries(
	test_std_vector_op
	GTest::gtest_main zsl
)

add_subdirectory(basics)
add_subdirectory(zatlab)

include(GoogleTest)
gtest_discover_tests(test_std_vector_op)

