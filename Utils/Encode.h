//
// Created by Krish Katariya on 3/8/24.
//

#ifndef KATZIP_ENCODE_H
#define KATZIP_ENCODE_H

#endif //KATZIP_ENCODE_H
using namespace std;
#include <string>
#include <unordered_map>
void encode(unordered_map<char, string> huffmanEncoding, string outputFile, string inputFile);
unordered_map<char, string> generateHash(string pathname);