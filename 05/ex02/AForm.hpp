#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    class FormNotSignedException: public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Form is not signed";
        }
    };

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    AForm(const std::string &name, int signGrade, int executeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    virtual void beSigned(const Bureaucrat &bureaucrat) = 0;

    virtual void execute(const Bureaucrat &executor) const = 0;

private:
    const std::string name;
    bool signedStatus;
    const int signGrade;
    const int executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif