cmake_minimum_required(VERSION 3.20)
project(instrumentClass LANGUAGES CXX)

add_executable(instrumentClass instrumentClass.cpp instrumentClassMain.cpp)
target_compile_features(instrumentClass PRIVATE cxx_std_20)