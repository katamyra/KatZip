//
// Created by Krish Katariya on 2/20/24.
//

using namespace std;
#include <iostream>
#include "MinHeap.h"

struct MinHeapNode *createHuffManTree(char values[], int frequencies[], int size) {
    struct MinHeap *prioq = createAndBuildMinHeap(values, frequencies, size);
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

void HuffmanCodesPrinter(char item[], int freq[], int size) {
    struct MinHeapNode *root = createHuffManTree(item, freq, size);
    int arr[50], top = 0;

    printHuffmanCodes(root, arr, top);
}

string addVal(int arr[], int n) {
    string ans;

    for (int i = 0; i < n; ++i) {
        ans += to_string(arr[i]);
    }
    return ans;
}

unordered_map<char, string> buildHuffmanHashMap(MinHeapNode *root, int arr[], int top, unordered_map<char, string>& returnVal) {

    if (root -> left) {
        arr[top] = 0;
        buildHuffmanHashMap(root -> left, arr, top + 1, returnVal);
    }
    if (root -> right) {
        arr[top] = 1;
        buildHuffmanHashMap(root -> right, arr, top + 1, returnVal);
    }
    if (isLeaf(root)) {
        returnVal[root -> item] = addVal(arr, top);
    }
    return returnVal;

}

