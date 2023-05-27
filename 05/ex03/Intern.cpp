#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &obj) {
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
    (void)obj;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
    AForm *form = NULL;
    if (name == "ShrubberyCreationForm") {
        form = new ShrubberyCreationForm(target);
    } else if (name == "RobotomyRequestForm") {
        form = new RobotomyRequestForm(target);
    } else if (name == "PresidentialPardonForm") {
        form = new PresidentialPardonForm(target);
    } else {
        throw InvalidFormNameException();
    }
    std::cout << "Intern creates " << name << std::endl;
    return form;
}

const char *Intern::InvalidFormNameException::what() const throw() {
    return "Invalid form name";
}