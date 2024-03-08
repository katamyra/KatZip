//
// Created by Krish Katariya on 3/7/24.
//

#include "Decode.h"
using namespace std;
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

unordered_map<string, char> decodeMap(ifstream& input) {

    int size;
    input.read(reinterpret_cast<char*>(&size), sizeof(size));
    unordered_map<string, char> huffmanMap;

    for (int i = 0; i < size; i++) {
        char character;
        input.get(character);

        unsigned char length;
        input.read(reinterpret_cast<char*>(&length), sizeof(length));

        string huffmanValue;
        for (int i = 0; i < length; i += 8) {
            char byte;
            input.read(&byte, sizeof(byte));

            bitset<8> bits(byte);
            string byteString = bits.to_string();
            huffmanValue += byteString.substr(8 - min(8, length - i));
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
    unordered_map<string, char> huffmanEncoding = decodeMap(input);

    string dummyLine;
    getline(input, dummyLine);

    string huffmanValue;
    char c;
    while (input.get(c)) {
        bitset<8> bits(c);
        string byteString = bits.to_string();

        for (char bit : byteString) {
            huffmanValue += bit;

            auto it = huffmanEncoding.find(huffmanValue);
            if (it != huffmanEncoding.end()) {
                output << it->second;
                cout << "decoding:" << huffmanValue << "to: " << it -> second << endl;
                huffmanValue.clear();
            }
        }
    }
    if (!huffmanValue.empty()) {
        auto it = huffmanEncoding.find(huffmanValue);
        if (it != huffmanEncoding.end()) {
            output << it->second;
        }
    }
    input.close();
    output.close();
    cout << "Decoding completed" << endl;
}

int main() {
    decode("../Output/output.kat", "../Output/decoded.txt");
}
