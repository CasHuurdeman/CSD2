cmake_minimum_required(VERSION 3.20)
project(Microphones LANGUAGES CXX)

add_executable(Microphones microphoneClass.cpp)
target_compile_features(Microphones PRIVATE cxx_std_20)