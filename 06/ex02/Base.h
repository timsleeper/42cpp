#ifndef BASE_H
#define BASE_H

class Base {
public:
    Base();
    virtual ~Base();
    virtual const char* identify() = 0;
};

#endif
