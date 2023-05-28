#include <iostream>
#include <list>
#include <vector>
#include "easyfind.h"

int main() {
    // std::vector<int> v = {1, 2, 3, 4, 5};
    // std::list<int> l = {10, 20, 30, 40, 50};

    std::vector<int> v;
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
    }

    std::list<int> l;
    for (int i = 10; i <= 50; i += 10) {
        l.push_back(i);
    }

    std::cout << "Testing vector with existing value:\n";
    std::cout << "Expected Result: Position of value 3 in vector is 2\n";
    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Actual Result: Position of value 3 in vector is " << std::distance(v.begin(), it) << "\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTesting vector with non-existing value:\n";
    std::cout << "Expected Result: Exception - Value not found\n";
    try {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "Actual Result: Position of value 6 in vector is " << std::distance(v.begin(), it) << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Actual Result: " << e.what() << '\n';
    }

    std::cout << "\nTesting list with existing value:\n";
    std::cout << "Expected Result: Position of value 30 in list is 2\n";
    try {
        std::list<int>::iterator it = easyfind(l, 30);
        std::cout << "Actual Result: Position of value 30 in list is " << std::distance(l.begin(), it) << "\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTesting list with non-existing value:\n";
    std::cout << "Expected Result: Exception - Value not found\n";
    try {
        std::list<int>::iterator it = easyfind(l, 60);
        std::cout << "Actual Result: Position of value 60 in list is " << std::distance(l.begin(), it) << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Actual Result: " << e.what() << '\n';
    }

    return 0;
}
