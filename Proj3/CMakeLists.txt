
cmake_minimum_required (VERSION 3.8)
project (proj3)
set(CMAKE_CXX_STANDARD 17)

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)
add_subdirectory(matplotplusplus)
include_directories(include)
file(GLOB SOURCES src/*.cpp)
pybind11_add_module(proj3 pyth/pythonlib.cpp)
target_link_libraries(proj 3PRIVATE matplot)

