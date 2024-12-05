cmake_minimum_required(VERSION 3.20)
project(instrumentClass LANGUAGES CXX)

add_executable(instrumentInheritance instrument.cpp main.cpp)
target_compile_features(instrumentInheritance PRIVATE cxx_std_20)