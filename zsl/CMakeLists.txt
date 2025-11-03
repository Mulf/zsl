add_library(zsl STATIC "")
add_subdirectory(3rd_party)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_sources(
    zsl
    PRIVATE
        # basics
        include/zsl.h
        include/basics/basics.h
        include/basics/check.h
        include/basics/copy_control.h
        include/basics/defines.h
        include/basics/ZException.h
        src/basics/ZException.cpp
        # Langugage Fundamentals
        include/zatlab/language_fundamentals/matrices_and_arrays.h
        include/zatlab/language_fundamentals/operators_and_elementary_operations/arithmetic_operations.h 
        include/zatlab/language_fundamentals/operators_and_elementary_operations/operators_and_elementary_operations.h 

        src/zatlab/language_fundamentals/matrices_and_arrays.cpp
        src/zatlab/language_fundamentals/matrices_and_arrays_indexing.cpp
        src/zatlab/language_fundamentals/operators_and_elementary_operations/arithmetic_operations.cpp 
        # Data Import and Analysis
        include/zatlab/data_import_and_analysis/data_import_and_export.h
        include/zatlab/data_import_and_analysis/data_process.h
        include/zatlab/data_import_and_analysis/descriptive_statistics.h
        src/zatlab/data_import_and_analysis/data_import_and_export.cpp
        src/zatlab/data_import_and_analysis/data_process.cpp
        src/zatlab/data_import_and_analysis/descriptive_statistics.cpp
        # Mathematics
        include/zatlab/mathematics/elementary_math/trigonometry.h
        include/zatlab/mathematics/elementary_math/exponents_and_logarithms.h
        include/zatlab/mathematics/elementary_math/constants_and_test_matrices.h 
        include/zatlab/mathematics/elementary_math/complex_numbers.h
        include/zatlab/mathematics/random_number_generation.h
        include/zatlab/mathematics/fourier_analysis_and_filtering.h
        include/zatlab/mathematics/interpolation.h
        src/zatlab/mathematics/elementary_math/trigonometry.cpp
        src/zatlab/mathematics/elementary_math/exponents_and_logarithms.cpp
        src/zatlab/mathematics/elementary_math/constants_and_test_matrices.cpp 
        src/zatlab/mathematics/elementary_math/complex_numbers.cpp
        src/zatlab/mathematics/random_number_generation.cpp
        src/zatlab/mathematics/fourier_analysis_and_filtering.cpp
        src/zatlab/mathematics/interpolation.cpp
)

target_include_directories(zsl
    PUBLIC
        include
        3rd_party
    #PRIVATE    
    #    include/basics
    #    include/zatlab
    #    include/zatlab/language_fundamentals
    #    include/zatlab/language_fundamentals/operators_and_elementary_operations
)

target_link_libraries(
    zsl 
    PRIVATE gsl
)