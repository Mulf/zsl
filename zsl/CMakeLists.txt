
add_library(zsl STATIC "")
add_subdirectory(3rd_party)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_sources(
    zsl
    PRIVATE
        include/zsl.h
        src/basics/ZException.cpp
        src/basics/std_vector_op.cpp
        src/zatlab/language_fundamental/matrices_and_arrays.cpp
        src/zatlab/language_fundamental/matrices_and_arrays_indexing.cpp
        src/zatlab/language_fundamental/operators_and_elementary_operations/arithmetic_operations.cpp 
        src/zatlab/data_import_and_analysis/data_import_and_export.cpp
        src/zatlab/mathematics/elementary_math.cpp
  "src/zatlab/mathematics/random_number_generation.cpp")

target_include_directories(zsl
    PUBLIC
        include
    PRIVATE
        include/basics
        include/zatlab
        include/zatlab/language_fundamentals
        include/zatlab/language_fundamentals/operators_and_elementary_operations
)

target_link_libraries(
    zsl 
    PRIVATE alglib
)