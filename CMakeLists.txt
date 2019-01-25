cmake_minimum_required(VERSION 3.13)
project(FindDeterminant C)
add_compile_options(-Wall -Werror)

set(CMAKE_C_STANDARD 11)
set (SOURCES main.c matrix.c matrix.h)
add_executable(FindDeterminant ${SOURCES})

set_target_properties(FindDeterminant
        PROPERTIES
        OUTPUT_NAME "FindDeterminant"
        SUFFIX ".out")
target_link_libraries(FindDeterminant m)