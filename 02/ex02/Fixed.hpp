#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed& src);
    ~Fixed();

    Fixed& operator=(const Fixed& src);
    Fixed operator+(const Fixed& src) const;
    Fixed operator-(const Fixed& src) const;
    Fixed operator*(const Fixed& src) const;
    Fixed operator/(const Fixed& src) const;
    bool operator>(const Fixed& src) const;
    bool operator<(const Fixed& src) const;
    bool operator>=(const Fixed& src) const;
    bool operator<=(const Fixed& src) const;
    bool operator==(const Fixed& src) const;
    bool operator!=(const Fixed& src) const;
    Fixed& operator++();    // Prefix increment
    Fixed operator++(int);  // Postfix increment
    Fixed& operator--();    // Prefix decrement
    Fixed operator--(int);  // Postfix decrement

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);

};