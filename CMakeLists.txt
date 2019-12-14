cmake_minimum_required(VERSION 3.15)
project(Factory)

set(CMAKE_CXX_STANDARD 17)

add_executable(Factory main.cpp types.hpp package.hpp storage_types.hpp package.cpp storage_types.cpp)