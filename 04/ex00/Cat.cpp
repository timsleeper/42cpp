#include "Cat.h"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const {
    return type;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}