cmake_minimum_required(VERSION 3.24)
project(RoverVer3 C)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultiExample main.c map.h map.c rover.c rover.h)
