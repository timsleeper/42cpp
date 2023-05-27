#include "ScalarConverter.h"

//int main(int argc, char *argv[]) {
    // if (argc != 2) {
    //     std::cerr << "Usage: " << argv[0] << " <value_to_convert>" << std::endl;
    //     return 1;
    // }

    // ScalarConverter converter;
    // converter.convert(argv[1]);

int main() {
ScalarConverter converter;

std::cout << "Testing char conversion" << std::endl;
// Testing char conversion
converter.convert("'a'");
converter.convert("'z'");
converter.convert("'1'");
converter.convert("' '");
std::cout << std::endl;

std::cout << "Testing int conversion" << std::endl;
// Testing int conversion
converter.convert("42");
converter.convert("-42");
converter.convert("0");
std::cout << std::endl;

std::cout << "Testing float conversion" << std::endl;
// Testing float conversion
converter.convert("4.2f");
converter.convert("-4.2f");
converter.convert("0.0f");
converter.convert("-inff");
converter.convert("+inff");
converter.convert("nanf");
std::cout << std::endl;

std::cout << "Testing double conversion" << std::endl;
// Testing double conversion
converter.convert("4.2");
converter.convert("-4.2");
converter.convert("0.0");
converter.convert("-inf");
converter.convert("+inf");
converter.convert("nan");
std::cout << std::endl;

std::cout << "Testing conversion from char to other types" << std::endl;
// Test conversion from char to other types
converter.convert("'0'");
std::cout << std::endl;

std::cout << "Testing overflow" << std::endl;
// Test overflow
converter.convert("1000000000000000000000000000.0");
converter.convert("-1000000000000000000000000000.0");
std::cout << std::endl;

std::cout << "Testing underflow" << std::endl;
// Test underflow
converter.convert("0.0000000000000000000000000001");
converter.convert("-0.0000000000000000000000000001");
std::cout << std::endl;





    return 0;
}

