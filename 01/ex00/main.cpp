#include <iostream>
#include "Zombie.hpp"

int main()
{

    int num = 10;
    Zombie *horde = zombieHorde(num, "Tim");
    if (horde == NULL)
    {
        std::cerr << "Failed to create zombie horde" << std::endl;
        return 1;
    }

    for (int i = 0; i < num; i++)
        horde[i].announce();

    delete[] horde;

    return 0;
}
