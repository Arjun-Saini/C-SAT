cmake_minimum_required(VERSION 3.30)

project(csat)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-14")

add_executable(csat_solver
    src/main.cpp
    src/Solver.hpp
    src/Solver.cpp
    src/Parser.hpp
    src/Parser.cpp
    src/Literal.hpp
    src/Clause.hpp
    src/Clause.cpp
)

target_compile_options(csat_solver PRIVATE -std=c++20 -Wall)
