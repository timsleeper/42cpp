#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::filterAndPrint(const std::string &logLevel)
{
    LogLevel level = stringToLogLevel(logLevel);
    if (level != INVALID)
    {
        printMessages(level);
    }
    else
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

Harl::LogLevel Harl::stringToLogLevel(const std::string &logLevelStr)
{
    LogLevel logLevel;
    if (logLevelStr == "WARNING")
    {
        logLevel = WARNING;
    }
    else if (logLevelStr == "ERROR")
    {
        logLevel = ERROR;
    }
    else
    {
        logLevel = INVALID;
    }
    return logLevel;
}

void Harl::printMessages(LogLevel logLevel)
{
    switch (logLevel)
    {
    case WARNING:
        std::cout << "[ WARNING ]" << std::endl;
        std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
        std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
    case ERROR:
        std::cout << "[ ERROR ]" << std::endl;
        std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
        break;
    default:
        break;
    }
}
