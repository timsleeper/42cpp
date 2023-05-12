#include "Harl.hpp"
#include <iostream>

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

    const char *logLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunction funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    size_t numLogLevels = sizeof(logLevels) / sizeof(logLevels[0]);

    for (size_t i = 0; i < numLogLevels; ++i)
    {
        if (logLevels[i] == level)
        {
            (this->*funcs[i])();
            break;
        }
    }
}
