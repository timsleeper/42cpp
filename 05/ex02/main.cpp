#include <iostream>
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"


int main() {

    std::cout << "Bureaucrat: Required grades: 1-150" << std::endl;

    std::cout << "Testing creating a Bureau with grade 151" << std::endl;
    try{
        Bureaucrat Lincoln("Lincoln", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Testing creating a Bureau with grade -1" << std::endl;
    try{
        Bureaucrat Lincoln("Lincoln", -1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Testing creating a Bureaucrat Obama with grade 1" << std::endl;
    Bureaucrat Obama("Obama", 1);
    std::cout << Obama;

    std::cout << "Testing creating a Bureaucrat ObamaLow with grade 150" << std::endl;
    Bureaucrat ObamaLow("Obama", 150);
    std::cout << ObamaLow;

    std::cout << "Incrementing grade already at maximum (1)" << std::endl;
    try {
        Obama.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << Obama;

    std::cout << "Decrementing grade already at minimum (150)" << std::endl;
    try {
        ObamaLow.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Testing decrementing grade. Should be (2)" << std::endl;
    try {
        Obama.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << Obama;

    std::cout << "PresidentialPardonForm: Required grades: sign 25, exec 5" << std::endl;
    PresidentialPardonForm form("Hillary Clinton");
    try {
        Obama.signForm(form);
        Obama.executeForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    for (int i = Obama.getGrade(); i < 6; i++) {
        Obama.decrementGrade();
    }

    std::cout << "PresidentialPardonForm: Testing grade to low to execute:" << std::endl;
    try {
        Obama.signForm(form);
        Obama.executeForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "ShrubberyCreationForm: Required grades: sign 145, exec 137" << std::endl;
    ShrubberyCreationForm form2("Greenpeace");
    try {
        Obama.signForm(form2);
        Obama.executeForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "RobotomyRequestForm: Required grades: sign 72, exec 45" << std::endl;
    RobotomyRequestForm form3("DeathRowInmate");
    try {
        Obama.signForm(form3);
        Obama.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;

}
