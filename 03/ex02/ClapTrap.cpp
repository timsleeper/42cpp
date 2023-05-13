#include "ClapTrap.h"
#include <iostream>

// Constructor
ClapTrap::ClapTrap(const std::string &name) : Name(name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << Name << " has been created." << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap " << other.Name << " has been created by copying." << std::endl;
    *this = other;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout << "ClapTrap " << Name << " has been assigned by copying." << std::endl;
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't attack " << target << " due to lack of energy or health." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    Hit_points -= amount;
    if (Hit_points < 0)
    {
        Hit_points = 0;
    }
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points > 0)
    {
        Energy_points--;
        Hit_points += amount;
        std::cout << "ClapTrap " << Name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't repair itself due to lack of energy." << std::endl;
    }
}
