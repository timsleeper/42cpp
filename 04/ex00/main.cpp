#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongCat.h"

int main() {
    const Animal* realAnimal = new Animal();
    const Animal* realDog = new Dog();
    const Animal* realCat = new Cat();
    const WrongAnimal* fakeCat = new WrongCat();

    std::cout << realDog->getType() << " " << std::endl;
    std::cout << realCat->getType() << " " << std::endl;
    std::cout << fakeCat->getType() << " " << std::endl;
    realCat->makeSound();
    realDog->makeSound();
    fakeCat->makeSound();
    realAnimal->makeSound();

    delete realDog;
    delete realCat;
    delete fakeCat;
    delete realAnimal;

    return 0;
}
