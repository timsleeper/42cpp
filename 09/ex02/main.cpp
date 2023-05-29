#include "PmergeMe.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

bool isPositiveInteger(const char* str) {
    while(*str) {
        if(!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        std::cerr << "No sequence provided. Please enter a sequence of positive integers.\n";
        return 1;
    }

    int* array = new int[argc-1];
    for(int i = 1; i < argc; i++) {
        if(!isPositiveInteger(argv[i])) {
            std::cerr << "Invalid input. Only positive integers are allowed.\n";
            delete[] array;
            return 1;
        }
        array[i-1] = atoi(argv[i]);
    }

    try {
        PmergeMe pm;
        pm.fillContainers(array, argc-1);
        pm.displayResults();
    }
    catch(...) {
        std::cerr << "An error occurred during program execution.\n";
        delete[] array;
        return 1;
    }

    delete[] array;
    return 0;
}
