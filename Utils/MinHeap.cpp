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

void downHeap(struct MinHeap *minH, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minH -> size && minH -> array[left] -> freq < minH -> array[smallest] -> freq) {
        smallest = left;
    }
    if (right < minH->size && minH->array[right]->freq < minH->array[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swapMinHNode(&minH->array[smallest],
                     &minH->array[index]);
        downHeap(minH, smallest);
    }
}

int checkSizeOne(struct MinHeap *minH) {
    return (minH -> size == 1);
}

struct MinHeapNode *removeMin(struct MinHeap *minH) {
    struct MinHeapNode *temp = minH -> array[0];
    minH -> array[0] = minH -> array[minH -> size - 1];

    --minH -> size;
    downHeap(minH, 0);

    return temp;
}

void insertMinHeap(struct MinHeap *minH, struct MinHeapNode *minHNode) {
    ++minH -> size;
    int i = minH -> size - 1;

    while (i && minHNode -> freq < minH->array[(i - 1) / 2] -> freq) {
        minH->array[i] = minH->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minH -> array[i] = minHNode;

}






