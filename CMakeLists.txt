cmake_minimum_required(VERSION 3.29)
project(MathProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(MathProject main.cpp
        Output_Functions.cpp
        Output_Functions.h
        Helper_Functions.cpp
        Helper_Functions.h)
