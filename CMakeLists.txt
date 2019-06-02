cmake_minimum_required(VERSION 3.10)
project(MatriceGaussJordan)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)
add_subdirectory(code)
add_subdirectory(tests/matrice)
add_subdirectory(tests/matriceGJ)

find_library(matricesCode COMPONENTS REQUIRED)

add_executable(matrices main.cpp)
target_link_libraries(matrices matricesCode)
