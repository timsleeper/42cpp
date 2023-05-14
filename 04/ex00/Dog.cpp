#include "Dog.h"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
    return type;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}