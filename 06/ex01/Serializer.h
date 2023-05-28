#ifndef SERIALIZER_H
#define SERIALIZER_H

typedef unsigned long uintptr_t;

struct Data {
    int x;
};

class Serializer {
public:
    Serializer() {}
    Serializer(const Serializer& other) {}
    Serializer& operator=(const Serializer& other) { return *this; }
    ~Serializer() {}

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_H
