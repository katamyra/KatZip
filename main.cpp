#include <iostream>
#include <fstream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::ofstream outFile("./Output/out.kat", std::ios::app);

    outFile << "Testing blah blah blah" << std::endl;

    outFile.close();

    std::cout << "Reached here!";



    return 0;
}
