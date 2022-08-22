#include "animal.hpp"

int Animal::numberOfAnimals = 0;

Animal::Animal(std::string name, int age, std::string noise) {
    this->name = name;
    this->age = age;
    this->noise = noise;
    Animal::numberOfAnimals++;
}

Animal::~Animal() {
    std::cout << "Animal " << this->name << " has been destroyed." << std::endl;
    Animal::numberOfAnimals--;
}

Animal::Animal() {
    this->name = "Unknown";
    this->age = 0;
    this->noise = "Unknown";
    Animal::numberOfAnimals++;
}

std::string Animal::getName() {
    return this->name;
}

void Animal::setName(std::string name) {
    this->name = name;
}

int Animal::getAge() {
    return this->age;
}

void Animal::setAge(int age) {
    this->age = age;
}

void Animal::makeNoise() {
    // This function is virtual, so when this func. is
    // overriden the derived class version of this func. is
    // called, even if the object is created using an Animal
    // pointer or passed by ref/ptr as Animal.
    // (Check main.cpp for early and late binding examples.)
    std::cout << "Animal " << this->name << " says: " << this->noise << std::endl;
}

void Animal::setNoise(std::string noise) {
    this->noise = noise;
}
