//
//  main.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/7/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include <iostream>
#include "strings.hpp"
#include "tools.hpp"
#include "vectors.hpp"
#include "fileio.hpp"
#include "errors.hpp"
#include "memory.hpp"
#include "animal.hpp"
#include "dog.hpp"
#include "argReader.hpp"
#include "calculator.hpp"

// using namespace std; // Standard Library lives here
// using std::cout;
// using std::endl;

int main(int argc, const char * argv[]) {
//    strings();
//    vectors();
//    std::cout << factorial(0) << std::endl;
//    fileio();
//    errors();
//    memory();
//    argReader(argc, argv);

    /* Classes */
    // Create Animal object in stack
    Animal bunny("Jay", 2, "Hello!");
    std::cout << bunny.getName() << std::endl;
    std::cout << bunny.getAge() << std::endl;
    bunny.makeNoise(); // early bind
    // will delete(bunny) automatically after current func. finished

    // Create Animal object in heap
    Animal *cat = new Animal("Richard", 3, "Hello!");
    std::cout << (*cat).getName() << std::endl;
    std::cout << (*cat).getAge() << std::endl;
    (*cat).makeNoise(); // late bind to Animal
    delete(cat);

    // Create Dog:Animal object in stack
    Dog alf("Alf", 4, "Bark!");
    std::cout << alf.getName() << std::endl;
    std::cout << alf.getAge() << std::endl;
    alf.makeNoise(); // early bind to subclass function since it's Dog and stack
    alf.Animal::makeNoise(); // early bind to Animal explicitly (would be Dog implicitly)
    alf.goodBoyStatus();
    alf.makeGoodBoy();
    alf.goodBoyStatus();
    alf.makeBadBoy();
    alf.goodBoyStatus();
    // runtime will delete(rex) automatically after main() is done
    
    // Create Dog:Animal object in heap using Animal pointer
    Animal *rex = new Dog("Rex", 1, "Bark, Bark!");
    // since rex's actual type is Dog, but we're using an Animal
    // pointer, compiler will early bind makeNoise() call to
    // Animal class' func., unless late binding is used (meaning
    // makeNoise is virtual).
    rex->makeNoise();
    delete(rex);
    
    /* Calculator */
//    std::cout << calculate("(36/3)/(4*(54.3-52.3))") << std::endl; // 1.5

    /* Range (tools.cpp) */
//    for (auto element: range(5, 18)) std::cout << element << std::endl;
    
    /* Christmas Tree (tools.cpp) */
//    drawChristmasTree(5);
    
    /* Print (tools.cpp) */
//    std::string string1 = "Hello, World!";
//    std::string string2[] = { "One", "Two", "Three" };
//    print(string1);
//    print(string2);
//    print(26);
//    print('a');
    
    /* Rand (tools.cpp) */
//    srand(int(time(NULL))); // seed rand() with time
//    for (auto i: range(0, 10)) print(rand(0, 5));

    return 0;
}
