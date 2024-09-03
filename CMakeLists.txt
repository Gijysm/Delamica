cmake_minimum_required(VERSION 3.29)
project(Dela)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dela src/main.cpp
        src/Tokenization.h
        src/Parser.hpp
)
