#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
    // Constructor
    FragTrap(const std::string &name = "Unknown");

    // Copy Constructor
    FragTrap(const FragTrap &other);

    // Copy assignment operator
    FragTrap &operator=(const FragTrap &other);

    // Destructor
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys();
};
#endif
