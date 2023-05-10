#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harlFilter <LOG_LEVEL>" << std::endl;
        return 1;
    }

    std::string logLevel(argv[1]);
    Harl harl;
    harl.filterAndPrint(logLevel);

    return 0;
}
