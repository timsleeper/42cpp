#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>


class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int grade) throw(GradeTooHighException, GradeTooLowException);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
    virtual ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);

    void signForm(AForm &obj) const;
    void executeForm(const AForm &obj) const;

    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
