//
//  tools.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/15/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include "tools.hpp"

bool isNumber(const std::string &str) {
    try {
        std::stod(str);
    } catch(...) {
        return false;
    }
    return true;
}

int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

std::vector<int> range(int start, int end) {
    std::vector<int> range((end - start) + 1);
    std::iota(std::begin(range), std::end(range), start);
    return range;
}

void drawChristmasTree(int rowsCount) {
    // ___*
    // __***
    // _*****
    // *******
    
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < rowsCount - (i + 1); j++) std::cout << ' ';
        for (int j = 0; j < i * 2 + 1; j++) std::cout << '*';
        std::cout << std::endl;
    }
}

int rand(int start, int end) {
    return (std::rand() % (end + 1 - start)) + start; // + 1 for inclusive
}
