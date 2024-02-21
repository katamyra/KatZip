//
// Created by Krish Katariya on 2/20/24.
//



#include "MinHeap.h"

#define MAX_TREE_HEIGHT 50

struct MinHeapNode *newnode(char item, unsigned freq) {
    struct MinHeapNode *temp = ((struct MinHeapNode*) std::malloc(sizeof(struct MinHeapNode)));
    // Rest of the function implementation

    temp -> left = temp -> right = NULL;
    temp -> item = item;
    temp -> freq = freq;
    return temp;
}

struct MinHeap *createMinHeap(unsigned int capacity) {
    struct MinHeap *minH = (struct MinHeap *)(malloc(sizeof (struct MinHeap))); // ? can i use new instead?
    minH -> size = 0;
    minH -> capacity = 0;
    minH -> array = ((struct MinHeapNode **) malloc(sizeof(struct MinHeapNode)));
    return minH;
}

void swapMinHNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

