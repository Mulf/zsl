
add_library(zsl)

target_sources(zsl
    PRIVATE 
        src/std_vector_op.cpp
        src/ZException.cpp
)

target_include_directories(zsl
    PUBLIC
        include
)