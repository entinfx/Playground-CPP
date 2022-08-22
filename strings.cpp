#include <iostream>
#include <string>
#include "strings.hpp"
#include "tools.hpp"

void strings() {
    // Strings allocate fixed amount of memory statically and change
    // dynamically depending on use (stream input, different data).
    // Strings manage data automatically.
    // The catName object is stored in stack, points to memory in heap.
    std::string dogName("Alf"); // or dogName = "Alf";
    std::string catName;
    std::cout << "Enter cat name:" << std::endl;
    do {
        // getline() reads until '\n'
        // std::cin >> x; reads only 1 word or number
        // std::cin and std::cout are objects of iostream class in <iostream> header
        // getline() is a method of these objects
        getline(std::cin, catName);
    } while (catName.empty());

    std::cout << "You entered: " << catName << " (" << catName.size() << " characters)" << std::endl;

    // C++ strings can be combined with c strings
    std::string catAction = " purrs quietly...";
    std::cout << catName + catAction.c_str() << std::endl; // or:
    // std::cout << catName.append(catAction.c_str()) << std::endl;

    // Assign new value to a string
    std::string fullCatName = catName.assign(catName, 0, 5); // or with only 1st param.
    std::cout << fullCatName << std::endl;

    // Find, insert, erase & replace
    unsigned long int catActionIndex = catAction.find("quietly...", 0); // 0 is starting position
    std::cout << "Index: " << catActionIndex << std::endl;

    catAction.insert(6, " not so"); // inserts left from cursor
    std::cout << catName + catAction << std::endl;

    catAction.erase(catAction.find("..."), 3);
    std::cout << catName + catAction << std::endl;

    catAction.replace(catAction.find("not so quietly"), 14, "very loudly!");
    std::cout << catName + catAction << std::endl;

    // String to Double
    double pi;
    std::string piInput;
    std::cout << "Enter PI: " << std::endl;
    getline(std::cin, piInput);
    if (isNumber(piInput)) {
        pi = stod(piInput);
        std::cout << "You entered: " << pi << std::endl;
    } else {
        std::cout << "That's not a number" << std::endl;
    }

    // Strings comparison
    std::string aStr = "A";
    std::string bStr = "B";
    std::cout << "A compared to B: " << aStr.compare(bStr) << std::endl; // -1 cause greater alphabetically
}
