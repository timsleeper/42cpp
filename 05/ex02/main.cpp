#include <iostream>
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"


int main() {

    std::cout << "Bureaucrat: Required grades: 1-150" << std::endl;

    std::cout << "Testing creating a Bureau with grade 151" << std::endl;
    try{
        Bureaucrat Lincoln("Lincoln", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Testing creating a Bureau with grade 151" << std::endl;
    try{
        Bureaucrat Lincoln("Lincoln", -1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Testing creating a Bureaucrat Obama with grade 1" << std::endl;
    Bureaucrat Obama("Obama", 1);
    std::cout << Obama;

    std::cout << "Incrementing grade already at maximum (1)" << std::endl;
    try {
        Obama.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << Obama;

    std::cout << "Testing decrementing grade. Should be (2)" << std::endl;
    try {
        Obama.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << Obama;

    PresidentialPardonForm form("Hillary Clinton");
    try {
        Obama.signForm(form);
        Obama.executeForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "ShrubberyCreationForm: Required grades: sign 145, exec 137" << std::endl;
    return 0;

}
