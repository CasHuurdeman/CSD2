cmake_minimum_required(VERSION 3.20)
project(speaker LANGUAGES CXX)

add_executable(Speaker classInClass.cpp)
target_compile_features(Speaker PRIVATE cxx_std_20)