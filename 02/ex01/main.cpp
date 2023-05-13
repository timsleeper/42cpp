#include <iostream>
#include "Fixed.hpp"

int main(void){
    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
	std::cout << "--------- Original tests ---------" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as a integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as a integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as a integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as a integer" << std::endl;

	std::cout << "--------- Other tests ---------" << std::endl;
	
	// Test the constructors
    Fixed defaultFixed;
    std::cout << "Default Fixed: " << defaultFixed << std::endl;
    
    Fixed intFixed(42);
    std::cout << "Int Fixed: " << intFixed << std::endl;
    
    Fixed floatFixed(3.14159f);
    std::cout << "Float Fixed: " << floatFixed << std::endl;
    
    Fixed copyFixed(floatFixed);
    std::cout << "Copy Fixed: " << copyFixed << std::endl;
    
    // Test the assignment operator
    Fixed assignedFixed = intFixed;
    std::cout << "Assigned Fixed: " << assignedFixed << std::endl;
    
    // Test getRawBits and setRawBits
    int rawBits = intFixed.getRawBits();
    std::cout << "Raw Bits: " << rawBits << std::endl;
    
    copyFixed.setRawBits(rawBits);
    std::cout << "Copy with Set Raw Bits: " << copyFixed << std::endl;
    
    // Test toFloat and toInt
    float floatValue = floatFixed.toFloat();
    std::cout << "Float Value: " << floatValue << std::endl;
    
    int intValue = intFixed.toInt();
    std::cout << "Int Value: " << intValue << std::endl;
    
    // Test the ostream operator
    std::cout << "Fixed Point: " << floatFixed << std::endl;

    return 0;
}