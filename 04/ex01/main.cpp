#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "WrongCat.h"
#include "Animal.h"

int main() {

    const int arraySize = 10;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; i++){
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; i++){
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; i++){
        delete animals[i];
    }

    // Test Deep Copy
    Dog originalDog;
    originalDog.setIdea(0, "I am the original dog");
    Dog copyDog(originalDog);
    copyDog.setIdea(0, "I am the copy dog");

    std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied dog idea: " << copyDog.getIdea(0) << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "I am the original cat");
    Cat copyCat(originalCat);
    copyCat.setIdea(0, "I am the copy cat");

    std::cout << "Original cat idea: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Copied cat idea: " << copyCat.getIdea(0) << std::endl;

    return 0;
}
