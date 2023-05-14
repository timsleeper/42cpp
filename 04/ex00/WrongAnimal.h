#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
    virtual ~WrongAnimal();

    std::string getType() const;
    void makeSound() const;

protected:
    std::string type;
};

#endif
