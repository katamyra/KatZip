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
int isLeaf(struct MinHeapNode *root);
struct MinHeap *createMinHeap(unsigned capacity);
void swapMinHNode(struct MinHeapNode **a, struct MinHeapNode **b);
void downHeap(struct MinHeap *minHeap, int index);
int checkSizeOne(struct MinHeap *minH);
struct MinHeapNode *removeMin(struct MinHeap *minH);
void insertMinHeap(struct MinHeap *minH, struct MinHeapNode *minHNode);
void buildMinHeap(struct MinHeap *minH);
struct MinHeap *createMinHeap(char item[], int freq[], int size);
struct MinHeapNode *buildHFTree(char item[], int freq[], int size);
void HuffmanCodesPrinter(char item[], int freq[], int size);
void printHuffmanCodes(struct MinHeapNode *root, int arr[], int top);
#endif //KATZIP_MINHEAP_H


