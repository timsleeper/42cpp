#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue){
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue){
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src){
    std::cout << "Assignation operator called" << std::endl;
    if(this != &src)
        _value = src.getRawBits();
    return *this;
}

