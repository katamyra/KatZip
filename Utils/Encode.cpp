//
// Created by Krish Katariya on 2/20/24.
//

#include "HuffmanTree.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

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

int main() {
    unordered_map<char, int> testing = generateFrequencies("../Input/input.txt");
    char arr[testing.size()];
    int freq[testing.size()];
    int i = 0;

    for (const auto& pair : testing) { // generating hashmaps to use for HuffMan tree creation
        arr[i] = pair.first;
        freq[i] = pair.second;
        //std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        i++;
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinHeapNode *root = createHuffManTree(arr, freq, size);
    int arrV[50], top = 0;

    unordered_map<char, string> hashMap;
    buildHuffmanHashMap(root, arrV, top, hashMap);

    for (const auto& pair : hashMap) {
        //arr[i] = pair.first;
        //freq[i] = pair.second;
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        //i++;
    }


}

