cmake_minimum_required(VERSION 3.10)
project(matricesCode CXX)

set(SOURCE_FILES
        CException.cpp CException.h
        CMatriceCore.h
        CMatrice.h
        CParser.cpp CParser.h
        CParserMatrice.cpp CParserMatrice.h
        CMatriceExtractor.h
        CMatriceGaussJordan.h
        emptyFile.cpp
        )

add_library(matricesCode ${SOURCE_FILES})