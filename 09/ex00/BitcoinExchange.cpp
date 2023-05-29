#include "BitcoinExchange.h"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : rateData(other.rateData) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        rateData = other.rateData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::load(const std::string& file) {
    std::ifstream db(file.c_str());
    if (!db) {
        std::cerr << "Error: could not open file: " << file << std::endl;
        return;
    }

    // Skip the first line (header)
    std::string header;
    std::getline(db, header);

    std::string line;
    while (std::getline(db, line)) {
        std::stringstream ss(line);
        std::string date;
        float rate;
        if (!std::getline(ss, date, ',') || !(ss >> rate)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        rateData[date] = rate;
    }
    db.close();
}

float BitcoinExchange::getRate(const std::string& date) {
    std::stringstream ss(date);
    int year, month, day;
    char dash;
    
    if (!(ss >> year >> dash >> month >> dash >> day) || 
        dash != '-' || 
        year < 1 || year > 9999 || 
        month < 1 || month > 12 || 
        day < 1 || day > 31) {
        throw std::invalid_argument("Error: invalid date.");
    }
    
    std::map<std::string, float>::iterator it = rateData.lower_bound(date);
    if (it == rateData.end() || it->first != date) {
        if (it == rateData.begin()) {
            throw std::invalid_argument("Error: can't find the price for this date.");
        }
        --it; // get the previous (lower) date
    }
    return it->second;
}


