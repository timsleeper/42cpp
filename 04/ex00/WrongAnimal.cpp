#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("Generic Wrong Animal"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) : type(wrongAnimal.type){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal){
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    type = wrongAnimal.type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal sound..." << std::endl;
}
