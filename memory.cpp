#include <iostream>
#include "memory.hpp"
#include "animal.hpp"

void memory() {
    /* Pointer and reference operators are same as in C */
    int age = 22;
    int *agePtr = &age;
    std::cout << "age = " << age << " @ " << agePtr << std::endl; // or through dereferencing:
    std::cout << "age = " << *agePtr << " @ " << agePtr << std::endl;

    std::cout << std::endl;

    int ages[] = {15, 18, 21, 22};
    int *agesPtr = ages;
    for (int i = 0; i < sizeof(ages) / sizeof(*ages); i++) { // fucking hell
        std::cout << *(agesPtr + i) << std::endl; // will increment address by 4 bytes since sizeof(int) is 4
    }

    std::cout << std::endl;

    /* Constant pointers and pointers to constants */
    Animal *const monkey = new Animal("Jambo", 2, "Oh-ha-ha!"); // const ptr to object
    const Animal *cat = new Animal("Toaster", 4, "Bark!"); // ptr to const object
    // monkey = cat; // error, cannot modify pointer
    // cat->setAge(3); // error, cannot modify object
    delete monkey;
    delete cat;

    std::cout << std::endl;

    /* Pass by pointer */
    passByPointer(&age);
    std::cout << age << std::endl; // 23

    /* Pass by reference */
    passByReference(age);
    std::cout << age << std::endl; // 24
}

void passByPointer(int *age) {
    (*age)++;
}

void passByReference(int &age) {
    age++;
}
