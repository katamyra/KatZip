#include "./Utils/Decode.h"
#include "./Utils/Encode.h"
using namespace std;

int main() {
    decode("../Output/output.kat", "../Output/decoded.txt");
    //unordered_map<char, string> huffmanEncoding = generateHash("../Input/input.txt");
    //encode(huffmanEncoding, "../Output/output.kat", "../Input/input.txt");
}