#ifndef tools_hpp
#define tools_hpp

#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include "tools.hpp"

bool isNumber(const std::string &str);
int factorial(int n);
std::vector<int> range(int start, int end);
void drawChristmasTree(int rowsCount);
int rand(int start, int end);

// * Template functions are implicitly inlined, so when this header is
//   included in more than 1 file there are no multiple definitions of
//   these functions, and there are no linker errors. Instead, inline
//   will insert the functions' bodies at the place of call.

/* Templates (cannot be compiled, so header only) */
template <typename T>
void print(T data) {
    std::cout << data << std::endl;

    // TODO: Some safety can be reached with these:
    // if (std::is_array<T>::value) /* ... */
    // if (std::is_same<T, std::string>::value) /* ... */
}

template <typename T, size_t size>
void print(const T (&data)[size]) {
    for (auto element: data) std::cout << element << std::endl;
}

#endif
