#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "A new Zombie named " << name << " has risen from the dead!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BBraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is now dead... again!" << std::endl;
}