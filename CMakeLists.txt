cmake_minimum_required(VERSION 3.27)
project(KatZip)

set(CMAKE_CXX_STANDARD 17)

add_executable(KatZip main.cpp
        Utils/Encode.cpp
        Utils/Encode.h
        Utils/HuffmanTree.cpp
)
