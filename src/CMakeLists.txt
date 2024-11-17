cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(Main VERSION 0.0.2)

add_executable(main main.cpp)

set_target_properties(
    main PROPERTIES
    CXX_EXTENSIONS 14
    CXX_STANDARD_REQUIRED ON
)


target_include_directories(
    main
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    main
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(main lib)
