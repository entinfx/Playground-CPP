//
//  dog.hpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/16/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#ifndef dog_hpp
#define dog_hpp

#include "animal.hpp"

class Dog: public Animal { // public to access Animal's methods in Dog (otherwise implicitly private)
    bool isGoodBoy;
public:
    /* Inits */
    Dog(std::string name, int age, std::string noise);
    Dog();
    ~Dog();
    /* Methods */
    void goodBoyStatus();
    void makeGoodBoy();
    void makeBadBoy();
    void makeNoise();
};

#endif
