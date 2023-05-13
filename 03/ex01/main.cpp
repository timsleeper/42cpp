#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
    // Test the default constructor
    ClapTrap ct1("CT1");

    // Test the copy constructor
    ClapTrap ct2(ct1);

    // Test the copy assignment operator
    ClapTrap ct3 = ct1;

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

    // Test the takeDamage method until no hit points left
    for (int i = 0; i < 3; ++i)
    {
        ct1.takeDamage(5);
    }

    // Test the attack method when no hit points left
    ct1.attack("target1");

    // Test the beRepaired method when no hit points left
    ct1.beRepaired(5);

    // Test the ScavTrap class
    ScavTrap st1("ST1");

    // Test the copy constructor
    ScavTrap st2(st1);

    // Test the copy assignment operator
    ScavTrap st3 = st1;

    // Test the attack method
    st1.attack("target2");

    // Test the takeDamage method
    st1.takeDamage(25);

    // Test the beRepaired method
    st1.beRepaired(25);

    // Test the guardGate method
    st1.guardGate();

    // Test the attack method when no energy points left
    for (int i = 0; i < 51; ++i)
    {
        st1.attack("target2");
    }

    // Test the beRepaired method when no energy points left
    for (int i = 0; i < 51; ++i)
    {
        st1.beRepaired(25);
    }

    // Test the takeDamage method until no hit points left
    for (int i = 0; i < 5; ++i)
    {
        st1.takeDamage(25);
    }

    // Test the attack method when no hit points left
    st1.attack("target2");

    // Test the beRepaired method when no hit points left
    st1.beRepaired(25);

    return 0;
}
