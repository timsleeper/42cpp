#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    signedStatus = other.signedStatus;
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecuteGrade() const
{
    return executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    signedStatus = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}