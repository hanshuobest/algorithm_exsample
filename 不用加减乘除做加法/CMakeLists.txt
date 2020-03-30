cmake_minimum_required(VERSION 2.8.7)
project(add)

#set(CMAKE_BUILD_TYPE  Debug)
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(add main.cpp)