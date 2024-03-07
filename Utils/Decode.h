//
// Created by Krish Katariya on 3/7/24.
//

#ifndef KATZIP_DECODE_H
#define KATZIP_DECODE_H
#include <unordered_map>
using namespace std;

class Decode {
    pair<int, unordered_map<string, char>> decodeMap(string pathname);
    void decode(string inputPath, string outputPath);
};


#endif //KATZIP_DECODE_H
