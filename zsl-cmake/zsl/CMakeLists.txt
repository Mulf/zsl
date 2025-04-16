
add_library(zsl SHARED "")

target_sources(
    zsl
    PRIVATE
        src/basics/ZException.cpp
        src/zsl/std_vector_op.cpp
)

target_include_directories(zsl
    PUBLIC
        include
    PRIVATE
        include/zsl
        include/basics
)