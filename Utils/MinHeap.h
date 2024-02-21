//
// Created by Krish Katariya on 2/20/24.
//

#ifndef KATZIP_MINHEAP_H
#define KATZIP_MINHEAP_H
#include <iostream>

struct MinHeapNode {

    unsigned freq;
    char item;

    struct MinHeapNode *left, *right;

};

struct MinHeap {
    unsigned size;
    unsigned capacity;

    struct MinHeapNode **array;
};

struct MinHeapNode *newnode(char item, unsigned freq);
struct MinHeap *createMinHeap(unsigned capacity);
#endif //KATZIP_MINHEAP_H


