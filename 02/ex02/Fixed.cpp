#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int intValue)
{
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::Fixed(const float floatValue)
{
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &src)
{
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
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++_value;
    return tmp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --_value;
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