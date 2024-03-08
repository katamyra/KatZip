cmake_minimum_required(VERSION 3.27)
project(KatZip)

set(CMAKE_CXX_STANDARD 17)

add_executable(KatZip main.cpp
        Utils/Encode.cpp
        Utils/HuffmanTree.cpp
        Utils/MinHeap.cpp
        Utils/MinHeap.h
        Utils/HuffmanTree.h
        Utils/Decode.cpp
        Utils/Decode.h
        Utils/Encode.h
)
