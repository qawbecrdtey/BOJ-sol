cmake_minimum_required(VERSION 3.14)
project(BOJ_sol)

set(CMAKE_CXX_STANDARD 17)

# change the number to run the corresponding problem
add_executable(${PROJECT_NAME} problems/acmicpc_7523.cpp)