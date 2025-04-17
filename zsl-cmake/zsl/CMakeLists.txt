
add_library(zsl STATIC "")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_sources(
    zsl
    PRIVATE
        src/basics/ZException.cpp
        src/basics/std_vector_op.cpp
)

target_include_directories(zsl
    PUBLIC
        include
    PRIVATE
        include/zsl
        include/basics
)