#ifndef RPN_H
#define RPN_H

#include <stack>
#include <string>
#include <vector>

class RPN {
public:
    // Default constructor
    RPN();

    // Copy constructor
    RPN(const RPN& obj);

    // Assignment operator
    RPN& operator=(const RPN& obj);

    // Destructor
    ~RPN();

    int calculate(std::string expression);
    bool isValidExpression(const std::string& expression);
private:
    std::stack<int> stack;
};

#endif // RPN_H
