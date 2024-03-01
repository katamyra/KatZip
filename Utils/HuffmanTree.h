//
// Created by Krish Katariya on 2/23/24.
//

#ifndef KATZIP_HUFFMANTREE_H
#define KATZIP_HUFFMANTREE_H

#endif //KATZIP_HUFFMANTREE_H

#include <string>
#include <unordered_map>
#include "MinHeap.h"
using namespace std;
void HuffmanCodesPrinter(char item[], int freq[], int size);
unordered_map<char, string> buildHuffmanHashMap(MinHeapNode *root, int arr[], int top, unordered_map<char, string>& returnVal);
struct MinHeapNode *createHuffManTree(char values[], int frequencies[], int size);