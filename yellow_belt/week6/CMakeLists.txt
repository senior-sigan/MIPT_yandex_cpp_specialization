cmake_minimum_required(VERSION 3.13)
project(week6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wdangling-else -Wno-unused-parameter -Wdeprecated")
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(PROJECT_HEADERS_DIR)

add_executable(week6 ${SOURCES} ${HEADERS})
