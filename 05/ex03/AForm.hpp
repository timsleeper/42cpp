#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;

protected:
    virtual void executeOK() const = 0;

public:
    AForm();
    AForm(const std::string &name, const int signGrade, const int execGrade) throw(GradeTooHighException, GradeTooLowException);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &obj) throw(GradeTooLowException);

    virtual void execute(const Bureaucrat &executor) const throw(GradeTooLowException, FormNotSignedException);

    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
        virtual const char *what() const throw();
    };


};


#endif
