cmake_minimum_required(VERSION 3.10)
project(matricesCode CXX)

set(SOURCE_FILES
        CException.h
        CMatriceCore.h
        CMatrice.h
        CMatriceGaussJordan.h
        CMatriceExtractor.h
        CParser.h
        CParserMatrice.h
        emptyFile.cpp
        )

add_library(matricesCode ${SOURCE_FILES})