#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    std::string getType() const;
    void makeSound() const;
};

#endif
