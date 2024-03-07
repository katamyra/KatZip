//
// Created by Krish Katariya on 3/7/24.
//

#include "Decode.h"
using namespace std;
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

unordered_map<string, char> decodeMap(string pathname) {
    ifstream input(pathname, ios::binary);
    int size;
    input.read(reinterpret_cast<char*>(size), sizeof(size));
    unordered_map<string, char> huffmanMap;

    for (int i = 0; i < size; i++) {

        char character;
        input.get(character);

        int length;
        input.read(reinterpret_cast<char*>(&length), sizeof(length));

        string huffmanValue;
        for (int i = 0; i <= length; i += 8) {
            char byte;
            input.read(&byte, sizeof(byte));

            bitset<8> bits(byte);
            string byteString = bits.to_string();
            huffmanValue += byteString;
        }
        huffmanMap[huffmanValue] = character;

    }
    return huffmanMap;


}

void decode(string inputPath, string outputPath) {
    ifstream input(inputPath, ios::binary);
    if (!input.is_open()) {
        cerr << "Error opening input path";
    }

    ofstream output(outputPath);
    unordered_map<string, char> huffmanEncoding = decodeMap(inputPath);

    // ! NEED TO SKIP THRU MAP HERE


    while (!input.eof()) {
        int length;
        input.read(reinterpret_cast<char*>(&length), sizeof(length));
        string huffmanValue;
        for (int i = 0; i <= length; i += 8) {
            char byte;
            input.read(&byte, sizeof(byte));

            bitset<8> bits(byte);
            string byteString = bits.to_string();
            huffmanValue += byteString;
        }
        output << huffmanEncoding[huffmanValue];
    }

    cout << "Encoding completed" << endl;


}
