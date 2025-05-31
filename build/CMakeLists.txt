cmake_minimum_required(VERSION 3.10)
project(CChess)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_FILES ../src/*.c)

if (MSVC)
    add_compile_options("/source-charset:utf-8" "/execution-charset:utf-8")
endif()

add_executable(main ${SRC_FILES})

target_include_directories(main PRIVATE src)
