cmake_minimum_required(VERSION 3.23)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rubiks_Cube_Solver main.cpp Model/RubiksCube.cpp Model/RubiksCube.h Model/RubiksCube3DArray.cpp)
