cmake_minimum_required(VERSION 3.14)
project(DancingLinks C)

set(CMAKE_C_STANDARD 99)

add_executable(DancingLinks main.c dansing_solver.c dance.h map_create.c all_func.c)