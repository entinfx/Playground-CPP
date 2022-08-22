//
//  argReader.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/24/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

// !!!: cmd + shift + < to pass argv's in Xcode

#include <iostream>
#include "argReader.hpp"

void argReader(int argc, const char **argv) {
    // argc - number of argv *
 
    // ** points to each * that points to chars
    // * argv -> * (argv + 0) -> "arg1"
    //           * (argv + 1) -> "arg2"
    //           * (argv + 2) -> '\n'
    
    if (argc > 1) { // 1, cause the name of the program is the first arg added implicitly
        for (int i = 0; i < argc; i++) {
            std::cout << i << ": " << *(argv + i) << std::endl; // cout will print (* char) inline
        }
    }
}
