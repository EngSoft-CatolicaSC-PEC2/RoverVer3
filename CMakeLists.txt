cmake_minimum_required(VERSION 3.24)
project(RoverVer3 C)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultiExample main.c utils.h utils.c imprimir.h imprimir.c mapa.h mapa.c rover.c rover.h)
