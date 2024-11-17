cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(Exemple1 VERSION 0.0.2)

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

add_subdirectory(lib)
add_subdirectory(src)