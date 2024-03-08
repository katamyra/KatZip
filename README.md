# KatZip

A custom file compressor I created in order to learn c++ and better understand compression algorithms! It allows you to turn .txt files into .kat files. 

# Explanation 
KatZip uses the **huffman coding algorithm**, which uses a Huffman tree where each leaf node corresponds to 
a character in the input data, and each internal node corresponds to the sum of the frequencies of the nodes. 

This allows us to create a variable length codes where more often used letters have shorter codes allowing for smaller size files.

![Geeks for Geeks example of Huffman Tree](https://media.geeksforgeeks.org/wp-content/uploads/20230117162332/4.png)

# Usage 

In **main.cpp** file, use the following functions to encode a .txt file: 
```cpp
void encode(unordered_map<char, string> huffmanEncoding, string outputFile, string inputFile);
unordered_map<char, string> generateHash(string pathname);
```

You can also use the following function to decode a .txt file:
```cpp
void decode(string inputPath, string outputPath);
```

# Compression Example
```
On lorem ipsum 10 paragraph text:

Normal .txt size: 6123 bytes

Output.kat size: 3405 bytes
```
