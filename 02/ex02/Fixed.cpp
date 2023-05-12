#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        _value = src.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &src) const
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return Fixed(this->toFloat() / src.toFloat());
}

bool Fixed::operator>(const Fixed &src) const
{
    return this->_value > src._value;
}

bool Fixed::operator<(const Fixed &src) const
{
    return this->_value < src._value;
}

bool Fixed::operator>=(const Fixed &src) const
{
    return this->_value >= src._value;
}

bool Fixed::operator<=(const Fixed &src) const
{
    return this->_value <= src._value;
}

bool Fixed::operator==(const Fixed &src) const
{
    return this->_value == src._value;
}

bool Fixed::operator!=(const Fixed &src) const
{
    return this->_value != src._value;
}

Fixed &Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixedPoint)
{
    os << fixedPoint.toFloat();
    return os;
}