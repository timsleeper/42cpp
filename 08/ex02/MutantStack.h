#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <deque>
#include <stack>

#include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}

    // Updated copy constructor
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}

    // Assignment operator using the "copy-and-swap" idiom
    MutantStack &operator=(MutantStack other) {
        std::swap(this->c, other.c);
        return *this;
    }

    virtual ~MutantStack() {}

    typedef typename std::deque<T>::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};


#endif
