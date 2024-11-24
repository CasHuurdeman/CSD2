
cmake_minimum_required(VERSION 3.20)
project(oscillator LANGUAGES CXX)

add_executable(Oscillator oscillator.cpp main.cpp)
target_compile_features(Oscillator PRIVATE cxx_std_20)

 