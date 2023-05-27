#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade) throw(GradeTooHighException, GradeTooLowException) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        _signed = obj._signed;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat &obj) throw(GradeTooLowException) {
    if (obj.getGrade() > _signGrade) {
        throw GradeTooLowException();
    } else {
        _signed = true;
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &o, const AForm &obj) {
    o << obj.getName() << ", form is " << (obj.isSigned() ? "signed" : "not signed") << ", sign grade is " << obj.getSignGrade() << ", exec grade is " << obj.getExecGrade();
    return o;
}

void AForm::execute(const Bureaucrat &executor) const throw(GradeTooLowException, FormNotSignedException) {
    if (!isSigned()) {
        throw FormNotSignedException();
    } else if (executor.getGrade() > _execGrade) {
        throw GradeTooLowException();
    }
    this->executeOK();
}
