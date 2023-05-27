#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    virtual ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif