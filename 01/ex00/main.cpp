#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Tim");
    Zombie zombie2("Maia");
    randomChump("Ed");

    delete zombie1;

    return 0;
}