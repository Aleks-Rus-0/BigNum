cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(Library VERSION 0.0.3)

add_library(lib STATIC BigNumLib.h BigNumLib.cpp)

set_target_properties(
    lib PROPERTIES
    CXX_EXTENSIONS 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    lib
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)