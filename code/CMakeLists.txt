cmake_minimum_required(VERSION 3.10)
project(matricesCode CXX)

set(SOURCE_FILES
        CException.h
        CParser.cpp CParser.h
        CParserMatrice.cpp CParserMatrice.h
        CMatriceExtractor.h
        CMatriceGaussJordan.h
        CMatriceCore.h
        CMatrice.h
        emptyFile.cpp
        )

add_library(matricesCode ${SOURCE_FILES})