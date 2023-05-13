#include "ClapTrap.h"
#include <iostream>

int main()
{
    // Test the default constructor
    ClapTrap ct1("CT1");

    // Test the copy constructor
    ClapTrap ct2(ct1);

    // Test the copy assignment operator
    ClapTrap ct3 = ct2;

    // Test the attack method
    ct1.attack("target1");

    // Test the takeDamage method
    ct1.takeDamage(5);

    // Test the beRepaired method
    ct1.beRepaired(5);

    // Test the attack method when no energy points left
    for (int i = 0; i < 11; ++i)
    {
        ct1.attack("target1");
    }

    // Test the beRepaired method when no energy points left
    for (int i = 0; i < 11; ++i)
    {
        ct1.beRepaired(5);
    }

    // Test the takeDamage method when no hit points left
    for (int i = 0; i < 3; ++i)
    {
        ct1.takeDamage(5);
    }

    // Test the attach method when no hit points left
    ct1.attack("target1");

    // Test the beRepaired method when no hit points left
    ct1.beRepaired(5);

    return 0;
}