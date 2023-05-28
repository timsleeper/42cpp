#include <cstdlib>
#include <iostream>
#include <ctime>
#include "A.h"
#include "B.h"
#include "C.h"

Base* generate() {
    switch (rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        default:
            return new C;
    }
}

void identify(Base* p) {
    std::cout << p->identify() << std::endl;
    delete p; // delete pointer to prevent memory leak
}

void identify(Base& p) {
    std::cout << p.identify() << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // initialize random seed

    // Test generate and identify functions with pointers
    for(int i = 0; i < 10; ++i) {
        Base* base = generate();
        std::cout << "Generated instance pointer. Expecting: " << base->identify() << ". Actual: ";
        identify(base);  // This will delete base
    }

    // Test identify function with references
    A a;
    std::cout << "\nA instance reference. Expecting: A. Actual: ";
    identify(a);

    B b;
    std::cout << "\nB instance reference. Expecting: B. Actual: ";
    identify(b);

    C c;
    std::cout << "\nC instance reference. Expecting: C. Actual: ";
    identify(c);

    return 0;
}
