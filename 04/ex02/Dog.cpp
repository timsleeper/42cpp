#include "Dog.h"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other){
    brain = new Brain(*other.brain);
    type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    delete brain;
    brain = new Brain(*other.brain);
    AAnimal::operator=(other);
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
    return type;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}