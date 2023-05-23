#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
        throw AForm::GradeTooLowException();
    std::ofstream ofs(target + "_shrubbery");
    if (ofs.fail())
        throw std::runtime_error("Unable to create file");
    ofs << "ASCII trees\n";
    ofs.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::ofstream ofs(target + "_shrubbery");
    if (ofs.fail())
        throw std::runtime_error("Unable to create file");
    ofs << "ASCII trees\n";
    ofs.close();
}