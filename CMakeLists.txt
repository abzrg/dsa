cmake_minimum_required(VERSION 3.24)

project(dsa
    VERSION 0.1.0
    DESCRIPTION "Data Structures and Algorithms Implementation in C"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set (CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory(src)
