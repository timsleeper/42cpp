#include "AAnimal.h"

AAnimal::AAnimal() : type(""){
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type){
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    type = other.type;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const{
    return type;
}

void AAnimal::makeSound() const{
    std::cout << "AAnimal sound" << std::endl;
}