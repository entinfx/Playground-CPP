#include <iostream>
#include <fstream>
#include <string>
#include "fileio.hpp"

void fileio() {
    // File stream symbols:
    // ios::trunc - Default, can be ommited
    // ios::app - Append
    // ios::in - Read from file
    // ios::out - Write to file
    // ios::binary - Treat as binary

    /* Write */
    std::string spaceOddity = "Ground Control to Major Tom.";
    std::ofstream writer("path", std::ios::trunc);
    if (writer) {
        writer << spaceOddity << std::endl;
        writer.close();
    } else {
        std::cout << "ERROR: Unable to create file stream." << std::endl;
    }

    // Append:
    std::string spaceOddity2 = "Take your protein pills and put your helmet on.";
    std::ofstream writer2("path", std::ios::app);
    if (writer2) {
        writer2 << spaceOddity2 << std::endl;
        writer2.close();
    } else {
        std::cout << "ERROR: Unable to create file stream." << std::endl;
    }

    /* Read */
    char character;
    std::ifstream reader("path");
    if (reader) {
        while (!reader.eof()) {
            reader.get(character); // by character
            std::cout << character << std::endl;
        }
        reader.close();
    } else {
        std::cout << "ERROR: File stream wasn't created." << std::endl;
    }
}
