#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    virtual ~WrongAnimal();

    virtual std::string getType() const;
    virtual void makeSound() const;

protected:
    std::string type;
};

#endif
