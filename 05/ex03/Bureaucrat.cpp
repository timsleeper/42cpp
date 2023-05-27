#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) throw(GradeTooHighException, GradeTooLowException) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    } else {
        _grade = grade;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj) {
        _grade = obj._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
    if (_grade - 1 < 1) {
        throw GradeTooHighException();
    } else {
        _grade--;
    }
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    } else {
        _grade++;
    }
}

void Bureaucrat::signForm(AForm &obj) const {
    try {
        obj.beSigned(*this);
        std::cout << _name << " signs " << obj.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &obj) const {
    try {
        obj.execute(*this);
        std::cout << _name << " executes " << obj.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot execute " << obj.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}


