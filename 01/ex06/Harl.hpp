#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
public:
    void filterAndPrint(const std::string &logLevel);

private:
    enum LogLevel
    {
        INVALID = 0,
        PROBABLY_COMPLAINING,
        WARNING,
        ERROR
    };

    LogLevel stringToLogLevel(const std::string &logLevelStr);
    void printMessages(LogLevel logLevel);
};

#endif