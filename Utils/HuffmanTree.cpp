//
// Created by Krish Katariya on 2/20/24.
//

using namespace std;
#include <cstdlib>
#include <iostream>

struct MinHeapNode {
    char data;
    unsigned freq;

    struct MinHeapNode *left, *right;

};

struct MinHeap {
    unsigned size;

    unsigned capacity;

    struct MinHeapNode** array;
};

