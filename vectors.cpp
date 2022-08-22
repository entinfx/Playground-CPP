//
//  vectors.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/15/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include "vectors.hpp"

void vectors() {
    // Vectors' size can be changed unlike arrays
    std::vector<double> raysVect(10);

    /* Insert */
    double rays[6] = { 10.1, 12.2, 41.0, 32.9, .78, 34.19 };
    raysVect.insert(raysVect.begin(), rays, rays + (sizeof(rays) / sizeof(* rays)));
    std::cout << raysVect.at(5) << std::endl; // 34.19

    raysVect.insert(raysVect.begin() + 4, 44.0);
    std::cout << raysVect[4] << std::endl; // [4] is identical to .at(4) // 44

    /* push_back, pop_back */
    raysVect.push_back(31.17);
    // raysVect.pop_back();
    std::cout << raysVect.back() << std::endl; // returns last - 31.17
    std::cout << raysVect.front() << std::endl; // returns first - 10.1
    
    /* std::iota */
    std::vector<int> myVec(10);
    std::iota(std::begin(myVec), std::end(myVec), 0); // std method, fills vector from certain position
    // for (int i = 0; i < myVec.size(); i++) {
        // std::cout << myVec[i] << std::endl;
    // } // or:
    for (auto element: myVec) std::cout << element << std::endl;
}
