cmake_minimum_required(VERSION 3.10)
project(my_interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_interpreter
    test_lexer.cpp
    lexer.cpp
    token.cpp
)
