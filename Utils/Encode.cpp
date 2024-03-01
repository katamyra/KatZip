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

unordered_map<char, string> generateHash(string pathname) {
    unordered_map<char, int> testing = generateFrequencies(pathname);
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
    int arrV[1000], top = 0;
    unordered_map<char, string> hashMap;
    buildHuffmanHashMap(root, arrV, top, hashMap);

    return hashMap;

}

void encode(unordered_map<char, string> huffmanEncoding, string outputFile, string inputFile) {
    ofstream output(outputFile, ios::binary);
    if (!output) {
        cerr << "out put file not found!";
    }
//    for (const auto& pair : huffmanEncoding) {
//        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
//    }
    ifstream input(inputFile);
    if (!input) {
        output.close();
        cerr << "input file not found";
    }

    char c;
    while (input.get(c)) {
        string encoded = huffmanEncoding[c];
        if (!(huffmanEncoding.find(c) != huffmanEncoding.end())) {
            cout << "not in map!";
        }
        if (!encoded.empty()) {
            bitset<8> bits(encoded);
            char byte = static_cast<char>(bits.to_ulong());
            output.write(&byte, sizeof(byte));
        } else {
            cout << "issue with huffman encoding!" << " " << c << endl;
        }
    }
    input.close();
    output.close();

    cout << "Encoding completed." << endl;

}



int main() {
    unordered_map<char, string> huffmanEncoding = generateHash("../Input/input.txt");
    encode(huffmanEncoding, "../Output/output.kat", "../Input/input.txt");
    return 0;
}

