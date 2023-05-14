#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    std::string getType() const;
    void makeSound() const;
};

#endif
