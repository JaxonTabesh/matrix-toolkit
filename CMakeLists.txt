cmake_minimum_required(VERSION 3.20)
project(matrix-toolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(matrix-toolkit src/main.cpp include/matrix.hpp)
target_include_directories(matrix-toolkit PRIVATE include)