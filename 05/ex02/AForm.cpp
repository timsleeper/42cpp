#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
        : name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    signedStatus = other.signedStatus;
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return signedStatus;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    signedStatus = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}