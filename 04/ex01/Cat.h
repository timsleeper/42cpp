#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    std::string getType() const;
    void makeSound() const;
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);

private:
    Brain* brain;
};

#endif
