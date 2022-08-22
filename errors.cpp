#include <iostream>
#include "errors.hpp"

void errors() {
    /* Throw your own variables */
    int n = 0;

    try {
        if (n != 0) {
            10 / n;
        } else throw n; // throws whatever it has to catch {}
    } catch(int n) { // catches whatever throw throws it
        std::cout << "ERROR: Cannot divide by " << n << "." << std::endl;
    }

    /* Throw actual errors */
    bool badStuffHappened = true;
    try {
        if (badStuffHappened) throw std::runtime_error("badStuffHappened");
        // Anything else won't get executed if throw runs
    } catch(std::exception &e) {
        std::cout << "Handling exception: " << e.what() << std::endl;
    } catch(...) {
        std::cout << "Unknown error occurred." << std::endl;
    }
}
