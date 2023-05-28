#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
    Span(unsigned int N);
    Span(const Span &src);
    Span& operator=(const Span &src);
    ~Span();

    void addNumber(int num);
    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last);
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> _vec;
    unsigned int _N;
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
    if (std::distance(first, last) + _vec.size() > _N)
        throw std::runtime_error("Range exceeds Span capacity");
    _vec.insert(_vec.end(), first, last);
}

#endif
