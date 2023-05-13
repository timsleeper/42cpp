#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
private:
    std::string Name;
    int Hit_points;
    int Energy_points;
    int Attack_damage;

public:
    // Constructor
    ClapTrap(const std::string &name = "Unknown");

    // Copy Constructor
    ClapTrap(const ClapTrap &other);

    // Copy assignment operator
    ClapTrap &operator=(const ClapTrap &other);

    // Destructor
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif
