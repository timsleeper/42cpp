#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <limits>
#include <iostream>
#include <cstdlib>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    void convert(std::string);

private:
    void printChar(double);
    void printInt(double);
    void printFloat(double);
    void printDouble(double);
};


#endif
