
cmake_minimum_required(VERSION 3.20)
project(simpleInheritance LANGUAGES CXX)

add_executable(simpleInheritance cat.cpp dog.cpp pet.cpp main.cpp)
target_compile_features(simpleInheritance PRIVATE cxx_std_20)

 