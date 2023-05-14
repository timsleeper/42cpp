#include "WrongCat.h"

WrongCat::WrongCat(){
    this->type="WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat){
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat){
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    WrongAnimal::operator=(wrongCat);
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}
