//
//  dog.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/16/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include <iostream>
#include "dog.hpp"

// Use the superclass init
Dog::Dog(std::string name, int age, std::string noise): Animal(name, age, noise) {
    this->isGoodBoy = false;
}

// Init superclass properties manually without superclass init
// Dog::Dog(std::string name, int age, std::string noise) {
    // this -> setName(name);
    // this -> setAge(age);
    // this -> setNoise(noise);
    // this -> isGoodBoy = false;
// }

Dog::Dog() { // `: Animal()` is called automatically
    this->isGoodBoy = false;
}

Dog::~Dog() { // `: ~Animal()` is called automatically
    std::cout << "Dog " << this->getName() << " has been destroyed." << std::endl;
}

void Dog::makeGoodBoy() {
    this->isGoodBoy = true;
}

void Dog::makeBadBoy() {
    this->isGoodBoy = false;
}

void Dog::goodBoyStatus() {
    std::cout << ((this->isGoodBoy) ? "Good Boy!" : "Bad Boy!") << std::endl;
}

// Override
void Dog::makeNoise() {
    std::cout << "Dog " << this->getName() << " says: " << this->noise << std::endl;
}
