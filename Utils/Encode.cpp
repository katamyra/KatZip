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
void writeHeader(unordered_map<char, string> huffmanEncoding, ofstream& file) {
    int size = huffmanEncoding.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size)); //write # of huffman encodings for when we decode
    for (const auto& [character, code] : huffmanEncoding) {
        file.write(&character, sizeof(char)); //writing the assii value of the actual char

        unsigned char length = code.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length)); // writing length of the huffman encoding, incase the length of the code is more than a byte]
        for (int i = 0; i < code.size(); i+= 8) {
            bitset<8> bits(code.substr(i, 8));
            char byte = static_cast<char>(bits.to_ulong());
            file.write(&byte, sizeof(byte));
        }

    }
    char newline = '\n';
    file.write(&newline, sizeof(newline));

}
void encode(unordered_map<char, string> huffmanEncoding, string outputFile, string inputFile) {
    ofstream output(outputFile, ios::binary);
    if (!output) {
        cerr << "output file not found!";
    }
    for (const auto& pair : huffmanEncoding) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
    ifstream input(inputFile);
    if (!input) {
        output.close();
        cerr << "input file not found";
    }
    writeHeader(huffmanEncoding, output);

    char c;
    while (input.get(c)) {
        string encoded = huffmanEncoding[c];
        if (!(huffmanEncoding.find(c) != huffmanEncoding.end())) {
            cout << "not in map!";
        }
        if (!encoded.empty()) {
            bitset<8> bits(encoded);
            char byte = static_cast<char>(bits.to_ulong());
            //cout << "writing byte!";
            output.write(&byte, sizeof(byte));
        } else {
            cout << "issue with huffman encoding!" << " " << c << endl;
        }
    }
    input.close();
    output.close();

    cout << "Encoding completed." << endl;

}

//
//int main() {
//    unordered_map<char, string> huffmanEncoding = generateHash("../Input/input.txt");
//    encode(huffmanEncoding, "../Output/output.kat", "../Input/input.txt");
//    return 0;
//}
//
