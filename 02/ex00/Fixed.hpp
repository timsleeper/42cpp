#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
public:
    Fixed();
    Fixed(const Fixed& src);
    ~Fixed();

    Fixed& operator=(const Fixed& src);

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int _fractionalBits = 8;
};

#endif