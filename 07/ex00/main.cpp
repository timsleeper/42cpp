#include <iostream>
#include "whatever.h"

int main() {

    // Test with integers
    int a = 10;
    int b = 20;
    std::cout << "Testing with integers a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap, a should be 20 and b should be 10: actual a = " << a << ", b = " << b << std::endl;
    std::cout << "Min should be 10: actual " << min(a, b) << std::endl;
    std::cout << "Max should be 20: actual " << max(a, b) << std::endl;

    // Test with floats
    float x = 1.2f;
    float y = 1.2f;
    std::cout << "\nTesting with floats x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap, x and y should still be 1.2: actual x = " << x << ", y = " << y << std::endl;
    std::cout << "Min should be 1.2: actual " << min(x, y) << std::endl;
    std::cout << "Max should be 1.2: actual " << max(x, y) << std::endl;

    // Test with characters
    char c1 = 'a';
    char c2 = 'b';
    std::cout << "\nTesting with chars c1 = " << c1 << ", c2 = " << c2 << std::endl;
    swap(c1, c2);
    std::cout << "After swap, c1 should be 'b' and c2 should be 'a': actual c1 = " << c1 << ", c2 = " << c2 << std::endl;
    std::cout << "Min should be 'a': actual " << min(c1, c2) << std::endl;
    std::cout << "Max should be 'b': actual " << max(c1, c2) << std::endl;

    // Test with strings
    std::string s1 = "string_a123";
    std::string s2 = "string_b456";
    std::cout << "\nTesting with strings s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap, s1 should be 'string_b456' and s2 should be 'string_a123': actual s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "Min should be 'string_a123': actual " << min(s1, s2) << std::endl;
    std::cout << "Max should be 'string_b456': actual " << max(s1, s2) << std::endl;

    return 0;
}
