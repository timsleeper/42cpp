#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Test Bureaucrat creation and grade modifications
    try {
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << john << std::endl;

        john.decrementGrade();
        std::cout << john << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test Form creation, signing and execution
    Bureaucrat john("John", 50);
    Bureaucrat boss("Boss", 1);

    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Target1");
    PresidentialPardonForm pardonForm("Target2");

    // Signing forms
    boss.signForm(shrubberyForm);
    boss.signForm(robotomyForm);
    boss.signForm(pardonForm);

    // John tries to execute the forms (should fail due to low grade)
    john.executeForm(shrubberyForm);
    john.executeForm(robotomyForm);
    john.executeForm(pardonForm);

    // Boss executes the forms
    boss.executeForm(shrubberyForm);
    boss.executeForm(robotomyForm);
    boss.executeForm(pardonForm);

    return 0;
}
