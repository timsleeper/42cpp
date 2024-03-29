#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &wrongCat);
    WrongCat &operator=(const WrongCat &wrongCat);
    virtual ~WrongCat();

    std::string getType() const;
    void makeSound() const;
};

#endif
