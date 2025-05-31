
cmake_minimum_required (VERSION 3.8)
project (proj3)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(pybind11)
add_subdirectory(matplotplusplus)
include_directories(include)
file(GLOB SOURCES src/*.cpp)
pybind11_add_module(proj3 ${SOURCES} pyth/pythonlib.cpp)
target_link_libraries(proj3 PRIVATE matplot)

