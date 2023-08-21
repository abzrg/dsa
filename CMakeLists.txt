cmake_minimum_required(VERSION 3.24)

project(dsa
    VERSION 0.1.0
    DESCRIPTION "Data Structures and Algorithms Implementation in C"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set (CMAKE_EXPORT_COMPILE_COMMANDS True)

# src (user: serghei): https://stackoverflow.com/a/64294837/13041067
# To fully detect memory leaks set env var: ASAN_OPTIONS=detect_leaks=1
include(cmake/asan.cmake)

add_subdirectory(src)
