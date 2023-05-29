#include "RPN.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    RPN calculator;
    
    if(!calculator.isValidExpression(argv[1])) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    int result = calculator.calculate(argv[1]);
    if(result != -1) std::cout << result << std::endl;
    return 0;
}