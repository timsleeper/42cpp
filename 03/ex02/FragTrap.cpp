#include "FragTrap.h"
#include <iostream>

// Constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FrapTrap " << Name << " has been created." << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FrapTrap " << Name << " has been created by copying." << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout << "FrapTrap " << Name << " has been assigned by copying." << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FrapTrap " << Name << " has been destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << Name << " can't attack " << target << " due to lack of energy or health." << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << Name << " requests high five!" << std::endl;
}