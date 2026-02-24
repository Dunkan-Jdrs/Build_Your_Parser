cmake_minimum_required(VERSION 3.14)
project(My_Own_Parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(My_Own_Parser STATIC ${SOURCES})
target_include_directories(My_Own_Parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(tests)