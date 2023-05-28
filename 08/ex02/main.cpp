#include <iostream>
#include "MutantStack.h"

int main() {
    // Test 1: default constructor
    MutantStack<int> ms;
    std::cout << "Test 1: Default constructor.\n";
    std::cout << "Expected: Stack is empty.\n";
    std::cout << "Actual: Stack is " << (ms.empty() ? "empty.\n" : "not empty.\n");

    // Test 2: adding elements
    ms.push(10);
    ms.push(20);
    ms.push(30);
    std::cout << "Test 2: Adding elements.\n";
    std::cout << "Expected: Stack size is 3.\n";
    std::cout << "Actual: Stack size is " << ms.size() << ".\n";

    // Test 3: removing elements
    ms.pop();
    std::cout << "Test 3: Removing elements.\n";
    std::cout << "Expected: Stack size is 2 and top element is 20.\n";
    std::cout << "Actual: Stack size is " << ms.size() << " and top element is " << ms.top() << ".\n";

    // Test 4: copy constructor
    MutantStack<int> ms_copy(ms);
    std::cout << "Test 4: Copy constructor.\n";
    std::cout << "Expected: Copied stack size is 2 and top element is 20.\n";
    std::cout << "Actual: Copied stack size is " << ms_copy.size() << " and top element is " << ms_copy.top() << ".\n";

    // Test 5: assignment operator
    MutantStack<int> ms_assign;
    ms_assign = ms;
    std::cout << "Test 5: Assignment operator.\n";
    std::cout << "Expected: Assigned stack size is 2 and top element is 20.\n";
    std::cout << "Actual: Assigned stack size is " << ms_assign.size() << " and top element is " << ms_assign.top() << ".\n";

    // Test 6: iterator
    int count = 0;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        ++count;
    }
    std::cout << "Test 6: Iterator.\n";
    std::cout << "Expected: Iterator should iterate over 2 elements.\n";
    std::cout << "Actual: Iterator iterated over " << count << " elements.\n";

    return 0;
}
