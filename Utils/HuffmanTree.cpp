//
// Created by Krish Katariya on 2/20/24.
//

using namespace std;
#include <iostream>
#include "MinHeap.h"

struct MinHeapNode *createHuffManTree(char values[], int frequencies[], int size) {
    struct MinHeap *prioq = createMinHeap(values, frequencies, size);
    while (!checkSizeOne(prioq)) {

        struct MinHeapNode *left = removeMin(prioq);
        struct MinHeapNode *right = removeMin(prioq);
        struct MinHeapNode *newn = newnode('X', left -> freq + right -> freq);

        newn -> left = left;
        newn -> right = right;
        insertMinHeap(prioq, newn);
    }
    return removeMin(prioq);
};

void HuffmanCodes(char item[], int freq[], int size) {
    struct MinHeapNode *root = createHuffManTree(item, freq, size);
    int arr[50], top = 0;

    printHuffmanCodes(root, arr, top);
}


