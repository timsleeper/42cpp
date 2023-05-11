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

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

private:
    int _value;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);

#endif