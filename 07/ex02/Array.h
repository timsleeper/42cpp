#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T>
class Array {
    T* elements;
    unsigned int n;

public:
    Array() : elements(NULL), n(0) { }

    Array(unsigned int n) : elements(new T[n]), n(n) { }

    Array(const Array<T>& other) : elements(new T[other.n]), n(other.n) {
        *this = other;
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            if (n != other.n) {
                delete[] elements;
                elements = NULL;
                n = other.n;
                if (n == 0) {
                    return *this;
                }
                elements = new T[n];
            }
            for (unsigned int i = 0; i < other.n; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] elements;
    }

    T& operator[](unsigned int index) {
        if (index >= n) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= n) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    unsigned int const & size() const {
        return n;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& o, Array<T> const &a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        o << a[i] << ' ';
    }
    return o;
}

#endif
