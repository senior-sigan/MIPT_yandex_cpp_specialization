cmake_minimum_required(VERSION 3.13)
project(week6)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(week6
        src/condition_parser.cpp
        src/condition_parser.h
        src/condition_parser_test.cpp
        src/database.cpp
        src/database.h
        src/date.cpp
        src/date.h
        src/main.cpp
        src/node.cpp
        src/node.h
        src/test_runner.h
        src/token.cpp
        src/token.h)
