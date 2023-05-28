#include <iostream>
#include "Serializer.h"

int main() {
    Data d;
    d.x = 123;

    std::cout << "Before serialization, d.x = " << d.x << std::endl;

    uintptr_t serialized = Serializer::serialize(&d);
    Data* deserialized = Serializer::deserialize(serialized);

    if (&d == deserialized) {
        std::cout << "Success: addresses match!" << std::endl;
    } else {
        std::cout << "Fail: addresses do not match!" << std::endl;
    }

    std::cout << "After deserialization, deserialized->x = " << deserialized->x << std::endl;

    return 0;
}
