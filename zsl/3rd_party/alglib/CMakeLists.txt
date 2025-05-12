# Set the name of the library
set(LIBRARY_NAME alglib)

# Define the directory containing the source files
set(SOURCE_DIR src)

# Use file(GLOB) to find all .cpp files in the source directory
file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp")

# Create the library, using the collected source files
add_library(${LIBRARY_NAME} ${SOURCE_FILES})

# Optionally, specify include directories if needed
target_include_directories(
    ${LIBRARY_NAME} 
    PUBLIC  ${SOURCE_DIR}
)
