cmake_minimum_required(VERSION 3.10)
project(matricesTestsGJ)

set(SOURCE_FILES
        testsMatriceGaussJordan.cpp
        )

add_executable(matricesTestsGJ ${SOURCE_FILES})
target_link_libraries(matricesTestsGJ matricesCode)