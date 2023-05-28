#include <iostream>
#include "iter.h"

// Functions to be used with iter

template <typename V>
void printWhatever(V& num) {
    std::cout << num << std::endl;
}

void doubleNumber(int& num) {
    num *= 2;
}

void uppercaseChar(char& c) {
    c = toupper(c);
}

int main() {

    // Test with int array
    std::cout << "Test with int array:" << std::endl;
    int arr1[5] = {1, 2, 3, 4, 5};
    std::cout << "Before: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    iter(arr1, 5, doubleNumber);
    std::cout << "After applying doubleNumber: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Test with char array
    std::cout << "Test with char array:" << std::endl;
    char arr2[5] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Before: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    iter(arr2, 5, uppercaseChar);
    std::cout << "After applying uppercaseChar: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // Test with template function
    std::cout << "Test with template function:" << std::endl;
    iter(arr1, 5, printWhatever<int>);

    return 0;
}
