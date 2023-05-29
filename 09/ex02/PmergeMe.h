#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        
        template <typename T>
        void mergeInsertSort(T &container);
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        void fillContainers(const int *array, size_t size);
        void displayResults();
};

#endif //PMERGEME_H
