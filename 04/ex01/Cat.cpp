#include "Cat.h"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    delete brain;
    brain = new Brain(*other.brain);
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const {
    return type;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}