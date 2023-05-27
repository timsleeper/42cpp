#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::executeOK() const {
    std::ofstream fileWrite;
    std::string filename = _target + "_shrubbery";
    fileWrite.open(filename.c_str());
    if (fileWrite.fail()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    fileWrite << "      ccee88oo\n";
    fileWrite << "   C8O8O8Q8PoOb o8oo\n";
    fileWrite << "dOB69QO8PdUOpugoO9bD\n";
    fileWrite << "CgggbU8OU qOp qOdoUOdcb\n";
    fileWrite << "         8UU  /pU  8UU\n";
    fileWrite << "          \\\\\\//  \\\\\\//\n";
    fileWrite << "           |||    |||\n";
    fileWrite << "           |||    |||\n";
    fileWrite << "           |||    |||\n";
    fileWrite << "  ..........//     \\\\..........\n";
    fileWrite.close();
}