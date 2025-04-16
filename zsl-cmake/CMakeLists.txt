cmake_minimum_required(VERSION 3.16)
project(zsl VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard (adjust as needed)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file("config.h.in" "config.h")

add_executable(Demo main.cpp)

target_include_directories(Demo PUBLIC "${PROJECT_BINARY_DIR}")

add_subdirectory(zsl)

target_link_libraries(Demo zsl)


enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)