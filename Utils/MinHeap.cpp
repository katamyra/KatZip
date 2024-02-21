//
// Created by Krish Katariya on 2/20/24.
//



#include "MinHeap.h"

struct MinHeapNode *newnode(char item, unsigned freq) {
    struct MinHeapNode *temp = ((struct MinHeapNode*) std::malloc(sizeof(struct MinHeapNode)));
    // Rest of the function implementation

    temp -> left = temp -> right = NULL;
    temp -> item = item;
    temp -> freq = freq;
    return temp;
}

struct MinHeap *createMinHeap(unsigned int capacity) {
    struct MinHeap
}
