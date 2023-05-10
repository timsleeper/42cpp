#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burguer! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*HarlFunction)(void);
    std::map<std::string, HarlFunction> functions;

    functions["DEBUG"] = &Harl::debug;
    functions["INFO"] = &Harl::info;
    functions["WARNING"] = &Harl::warning;
    functions["ERROR"] = &Harl::error;

    HarlFunction func = functions[level];
    if (func)
        (this->*func)();
}