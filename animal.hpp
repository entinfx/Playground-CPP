#ifndef animal_hpp
#define animal_hpp

#include <iostream>

class Animal {
    std::string name;
    int age;
protected:
    std::string noise;
public:
    /* Inits */
    Animal(std::string name, int age, std::string noise);
    ~Animal();
    Animal();
    /* Vars */
    static int numberOfAnimals;
    /* Methods */
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    virtual void makeNoise();
    void setNoise(std::string noise);
};

#endif
