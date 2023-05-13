#include "ScavTrap.h"
#include <iostream>

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << Name << " has been created." << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << Name << " has been created by copying." << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout << "ScavTrap " << Name << " has been assigned by copying." << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << Name << " can't attack " << target << " due to lack of energy or health." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " has entered in Gate keeper mode." << std::endl;
}