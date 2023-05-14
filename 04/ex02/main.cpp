#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "AAnimal.h"

int main() {
    // Test instantiation of AAnimal (should result in compile error)
    // AAnimal animal;

    // Test instantiation and type of Dog
    Dog* dog = new Dog();
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();

    // Test instantiation and type of Cat
    Cat* cat = new Cat();
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();

    // Test deep copy
    Dog originalDog;
    originalDog.setIdea(0, "Chase tail");
    Dog copiedDog = originalDog;  // This invokes the copy constructor
    copiedDog.setIdea(0, "Chase ball");

    std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;  // Should output "Chase tail"
    std::cout << "Copied dog idea: " << copiedDog.getIdea(0) << std::endl;  // Should output "Chase ball"

    Cat originalCat;
    originalCat.setIdea(0, "Sleep all day");
    Cat copiedCat = originalCat;  // This invokes the copy constructor
    copiedCat.setIdea(0, "Catch mouse");

    std::cout << "Original cat idea: " << originalCat.getIdea(0) << std::endl;  // Should output "Sleep all day"
    std::cout << "Copied cat idea: " << copiedCat.getIdea(0) << std::endl;  // Should output "Catch mouse"

    // Test dynamic allocation and deletion
    const int numAnimals = 10;
    AAnimal** animals = new AAnimal*[numAnimals];

    for (int i = 0; i < numAnimals; ++i) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    delete[] animals;

    delete dog;
    delete cat;

    return 0;
}
