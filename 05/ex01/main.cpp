#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        // Create a Bureaucrat
        Bureaucrat b1("John Doe", 100);
        std::cout << b1 << std::endl;

        // Create a Form
        Form f1("Form 1", 90, 80);
        std::cout << f1 << std::endl;

        // Try signing the form by the bureaucrat
        b1.signForm(f1);

        // Output the updated form status
        std::cout << f1 << std::endl;

        // Create another Bureaucrat
        Bureaucrat b2("Jane Smith", 70);
        std::cout << b2 << std::endl;

        // Try signing the form by the second bureaucrat
        b2.signForm(f1);

        // Output the updated form status
        std::cout << f1 << std::endl;

        // Create a form with a high-grade requirement
        Form f2("Form 2", 150, 140);
        std::cout << f2 << std::endl;

        // Try signing the form by the second bureaucrat (grade too low)
        b2.signForm(f2);

        // Output the updated form status
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
