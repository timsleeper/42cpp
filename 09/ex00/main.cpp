#include "BitcoinExchange.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    btc.load("data.csv");
    
    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string date, tmp;
        float value;
        if (!std::getline(ss, date, '|') || !(ss >> value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        try {
            std::cout << date << " => " << value << " = " << value * btc.getRate(date) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    input.close();
    return 0;
}
