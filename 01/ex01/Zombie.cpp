#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {}

void Zombie::announce()
{
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}