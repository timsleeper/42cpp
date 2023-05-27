#include "ScalarConverter.h"
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str) {
    // Handle char
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
        printChar(str[1]);
        printInt(str[1]);
        printFloat(str[1]);
        printDouble(str[1]);
        return;
    }
    
    // Handle float
    if (str.find("f") != std::string::npos) {
        float val = std::strtof(str.c_str(), 0);
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
        return;
    }

    // Handle double
    std::stringstream ss(str);
    double val;
    ss >> val;
    
    if (val == std::numeric_limits<double>::infinity() || val == -std::numeric_limits<double>::infinity() || str == "nan") {
        printChar(val);
        printInt(val);
        printFloat(val);
        printDouble(val);
        return;
    }

    // Default to int
    printChar(static_cast<int>(val));
    printInt(static_cast<int>(val));
    printFloat(static_cast<int>(val));
    printDouble(static_cast<int>(val));
}



void ScalarConverter::printChar(double val) {
    if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max() || isnan(val)) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<char>(val))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double val) {
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || isnan(val)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
}

void ScalarConverter::printFloat(double val) {
    std::cout << std::fixed << std::setprecision(1);
    if (isnan(val)) {
        std::cout << "float: nanf" << std::endl;
    } else if (val == std::numeric_limits<float>::infinity()) {
        std::cout << "float: inff" << std::endl;
    } else if (val == -std::numeric_limits<float>::infinity()) {
        std::cout << "float: -inff" << std::endl;
    } else if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double val) {
    std::cout << std::fixed << std::setprecision(1);
    if (isnan(val)) {
        std::cout << "double: nan" << std::endl;
    } else if (val == std::numeric_limits<double>::infinity()) {
        std::cout << "double: inf" << std::endl;
    } else if (val == -std::numeric_limits<double>::infinity()) {
        std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "double: " << val << std::endl;
    }
}
