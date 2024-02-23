//
// Created by Krish Katariya on 2/20/24.
//

#include "HuffmanTree.h"
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Char | Huffman code ";
    cout << "\n----------------------\n";
    HuffmanCodes(arr, freq, size);
}

unordered_map<char, int> generateFrequencies(string pathname) {
    std::ifstream file(pathname);

    if (!file.is_open()) {
        cerr << "Error opening file. Invalid path?\n";
    }

    char c;
    unordered_map<char, int> frequencies;
    while (file.get(c)) {
        if (frequencies.find(c) != frequencies.end()) {
            frequencies[c]++;
        } else {
            frequencies[c] = 1;
        }
    }
    return frequencies;
}


