cmake_minimum_required(VERSION 3.8)
project(cpp_waste_recycling_bekor)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-error=unused-parameter")

set(SOURCE_FILES
        main.cpp
        Garbage.cpp Garbage.h
        PaperGarbage.cpp PaperGarbage.h
        PlasticGarbage.cpp PlasticGarbage.h
        DustbinContentError.hpp
        Dustbin.cpp Dustbin.h
        DustbinTests.hpp Dustbin9000.cpp Dustbin9000.h MetalGarbage.cpp MetalGarbage.h BottleCupGarbage.cpp BottleCupGarbage.h BottleCapException.hpp)

add_executable(cpp_waste_recycling_bekor ${SOURCE_FILES})