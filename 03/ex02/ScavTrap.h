#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
    // Constructor
    ScavTrap(const std::string &name = "Unknown");

    // Copy Constructor
    ScavTrap(const ScavTrap &other);

    // Copy assignment operator
    ScavTrap &operator=(const ScavTrap &other);

    // Destructor
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};
#endif
