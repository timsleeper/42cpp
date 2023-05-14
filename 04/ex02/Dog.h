#ifndef DOG_H
#define DOG_H

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    std::string getType() const;
    void makeSound() const;
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);

private:
    Brain* brain;
};

#endif
