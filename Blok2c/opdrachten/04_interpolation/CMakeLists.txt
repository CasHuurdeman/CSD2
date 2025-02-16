
add_library(interpolation STATIC interpolation.cpp)
target_compile_features(interpolation PUBLIC cxx_std_20)
target_include_directories(interpolation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})