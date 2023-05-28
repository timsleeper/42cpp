#include <iostream>
#include <list>
#include <ctime>
#include "Span.h"


void addNumberTest(Span &span, unsigned int N) {
    std::cout << "Adding numbers 1 to " << N << " one by one." << std::endl;
    for (unsigned int i = 1; i <= N; ++i) {
        span.addNumber(i);
    }
}

void addRangeTest(Span &span, std::list<int>::iterator begin, std::list<int>::iterator end) {
    std::cout << "Adding range of numbers to the Span." << std::endl;
    span.addRange(begin, end);
}

void shortestAndLongestSpanTest(Span &span) {
    std::cout << "Finding shortest and longest span." << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
}


int main() {

    std::cout << "-------------Standard Tests-----------------" << std::endl;
    Span sp1 = Span(5);

    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);

    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

    std::cout << "-------------More Tests-----------------" << std::endl;

    unsigned int N = 10000;

    // Initialize random seed
    srand(time(NULL));

    std::cout << "Testing Span of " << N << " elements\n";

    // Create Span object
    Span sp(N);
    std::cout << "Created Span object\n";

    // Add individual numbers
    for (unsigned int i = 0; i < N / 2; ++i) {
        int num = rand() % N;  // generate random number
        sp.addNumber(num);
    }
    std::cout << "Added " << N / 2 << " individual numbers\n";

    // Add range of numbers
    std::vector<int> nums;
    for (unsigned int i = 0; i < N / 2; ++i) {
        nums.push_back(rand() % N);  // generate random number
    }
    sp.addRange(nums.begin(), nums.end());
    std::cout << "Added " << N / 2 << " numbers from range\n";

    // Test shortest and longest span
    int shortest = sp.shortestSpan();
    int longest = sp.longestSpan();
    std::cout << "Shortest span: " << shortest << "\n";
    std::cout << "Longest span: " << longest << "\n";

    // Test adding more numbers than Span can hold
    try {
        sp.addNumber(0);
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    // Test shortest and longest span with not enough elements
    Span sp2(1);
    sp2.addNumber(1);
    try {
        sp2.shortestSpan();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    try {
        sp2.longestSpan();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    return 0;
}
