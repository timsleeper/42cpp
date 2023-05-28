// Span.cpp

#include "Span.h"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) : _vec(src._vec), _N(src._N) {}

Span& Span::operator=(const Span &src) {
    if (this != &src) {
        _vec = src._vec;
        _N = src._N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_vec.size() >= _N)
        throw std::runtime_error("Span is full");
    _vec.push_back(num);
}

int Span::shortestSpan() {
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough elements for a span");
    std::sort(_vec.begin(), _vec.end());
    int minSpan = *(_vec.begin() + 1) - *(_vec.begin());
    for (std::vector<int>::iterator it = _vec.begin() + 1; it != _vec.end() - 1; ++it) {
        int span = *(it + 1) - *it;
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough elements for a span");
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minMax = std::minmax_element(_vec.begin(), _vec.end());
    return *minMax.second - *minMax.first;
}
