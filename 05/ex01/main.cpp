#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // Test valid creation of Bureaucrat
    Bureaucrat b1("Fulano", 100);
    std::cout << b1 << std::endl;

    // Test incrementing grade
    b1.incrementGrade();
    std::cout << b1 << std::endl;

    // Test decrementing grade
    b1.decrementGrade();
    std::cout << b1 << std::endl;

    // Test grade too high exception
    try
    {
        Bureaucrat b2("Ciclano", 0);
        std::cout << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test grade too low exception
    try
    {
        Bureaucrat b3("Beltrano", 151);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}