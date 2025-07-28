
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(THIRD_PARTY_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(gsl)
#target_include_directories(gsl PUBLIC ${THIRD_PARTY_INCLUDE_DIR})