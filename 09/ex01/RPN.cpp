#include "RPN.h"
#include <sstream>
#include <iterator>
#include <list>
#include <iostream>

// Default constructor
RPN::RPN() { }

// Copy constructor
RPN::RPN(const RPN& obj) {
    this->stack = obj.stack;
}

// Assignment operator
RPN& RPN::operator=(const RPN& obj) {
    if(this != &obj) {
        this->stack = obj.stack;
    }
    return *this;
}

// Destructor
RPN::~RPN() {
    while(!stack.empty()) stack.pop();
}

bool RPN::isValidExpression(const std::string& expression) {
    if (expression.empty()) return false;

    std::string validChars = "0123456789 +-/*";
    for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
        if (validChars.find(*it) == std::string::npos) return false;
    }
    return true;
}


int RPN::calculate(std::string expression) {
    std::istringstream iss(expression);
    std::list<std::string> tokens;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(tokens));

    for(std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        std::string token = *it;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return -1;
            }
            int val2 = stack.top(); stack.pop();
            int val1 = stack.top(); stack.pop();
            
            if (token == "+") stack.push(val1 + val2);
            else if (token == "-") stack.push(val1 - val2);
            else if (token == "*") stack.push(val1 * val2);
            else if (token == "/") {
                if(val2 == 0) {
                    std::cerr << "Error" << std::endl;
                    return -1;
                }
                stack.push(val1 / val2);
            }
        }
        else {
            try {
                int num = std::stoi(token);
                stack.push(num);
                } catch(const std::out_of_range& e) {
                std::cerr << "Error: Number out of range" << std::endl;
                return -1;
                }
        }
    }

    if(stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    return stack.top();
}
