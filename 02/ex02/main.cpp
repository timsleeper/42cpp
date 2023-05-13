#include <iostream>
#include "Fixed.hpp"

int main (void){

	std::cout << "--------- Original tests ---------" << std::endl;

    Fixed a0;
    Fixed const b0( Fixed(5.05f) * Fixed(2));

    std::cout << a0 << std::endl;
    std::cout << ++a0 << std::endl;
    std::cout << a0 << std::endl;
    std::cout << a0++ << std::endl;
    std::cout << a0 << std::endl;

    std::cout << b0 << std::endl;
    std::cout << Fixed::max(a0, b0) << std::endl;

	std::cout << "--------- Other tests ---------" << std::endl;

    Fixed a;
    Fixed b(10);
    Fixed c(5.05f);
    Fixed d(b);
    Fixed e;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

    e = a + b;

    std::cout << "a + b = " << e << std::endl;

    e = b - a;

    std::cout << "b - a = " << e << std::endl;

    e = b * c;

    std::cout << "b * c = " << e << std::endl;

    e = b / c;

    std::cout << "b / c = " << e << std::endl;

    if (a > b)
        std::cout << "a > b" << std::endl;
    else
        std::cout << "a <= b" << std::endl;

    if (a < b)
        std::cout << "a < b" << std::endl;
    else
        std::cout << "a >= b" << std::endl;

    if (a == b)
        std::cout << "a == b" << std::endl;
    else
        std::cout << "a != b" << std::endl;

    a++;

    std::cout << "a (after a++) = " << a << std::endl;

    a--;

    std::cout << "a (after a--) = " << a << std::endl;

    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;

    return 0;
}