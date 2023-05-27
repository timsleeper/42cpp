#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);
    virtual ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target) const;

    class InvalidFormNameException : public std::exception {
        public:
        virtual const char *what() const throw();

    };
};
#endif
