#include "Brain.h"

Brain::Brain(){}

Brain::Brain(const Brain& brain){
    for (int i = 0; i < 100; i++)
        ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain){
    for (int i = 0; i < 100; i++)
        ideas[i] = brain.ideas[i];
    return *this;
}

Brain::~Brain(){}

std::string Brain::getIdea(int index) const{
    return ideas[index];
}

void Brain::setIdea(int index, std::string idea){
    ideas[index] = idea;
}

