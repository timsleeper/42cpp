#include <iostream>
#include <string>

int main()
{
    // Initialize the string variable
    std::string str = "HI THIS IS BRAIN";

    // Initialize the pointer and reference to the string
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // Print memory addresses
    std::cout << "Address of str: " << &str << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;

    // Print values
    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}