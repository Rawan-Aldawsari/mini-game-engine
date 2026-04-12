cmake_minimum_required(VERSION 3.16)
project(GameArchitectureEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compile flags: warnings + optimization
add_compile_options(-Wall -Wextra -O2)

add_executable(GameEngine main.cpp)

target_include_directories(GameEngine PRIVATE include)
