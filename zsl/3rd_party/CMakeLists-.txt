# Define the directory containing the source files
set(ALGLIB_SRC alglib/src)

# Use file(GLOB) to find all .cpp files in the source directory
file(GLOB ALGLIB_SRC_FILES "${ALGLIB_SRC}/*.cpp")

add_library(alglib ${ALGLIB_SRC_FILES})
target_include_directories(
	alglib
	PUBLIC ${ALGLIB_SRC}
)
