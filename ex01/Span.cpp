#include "Span.hpp"

// default constructor
Span::Span() : N(0) {}

// parameterized constructor
Span::Span(unsigned int N) : N(N) {}

// copy constructor
Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

// copy assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

// destructor
Span::~Span() {}

// add a single number to the span
void Span::addNumber(int number) {
    if (numbers.size() >= N)
        throw std::runtime_error("Span is full");
    numbers.push_back(number);
}

// find the shortest span
// By sorting first, we know the smallest difference must be between two neighboring numbers
unsigned int Span::shortestSpan() const {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    // create a copy of the numbers vector so we don't modify the original
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = static_cast<unsigned int>(4294967295); // Maximum possible value
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        // this compares two values and returns the smaller one
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

// find the longest span
unsigned int Span::longestSpan() const {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());
    
    return static_cast<unsigned int>(*max - *min);
}