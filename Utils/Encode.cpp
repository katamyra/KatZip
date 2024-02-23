//
// Created by Krish Katariya on 2/20/24.
//
#include "MinHeap.h"
#include <iostream>
using namespace std;

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Char | Huffman code ";
    cout << "\n----------------------\n";
    HuffmanCodes(arr, freq, size);
}
