cmake_minimum_required(VERSION 3.8)
project(cpp_rest_api)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp User.cpp User.h UserService.cpp UserService.h)
add_executable(cpp_rest_api ${SOURCE_FILES})