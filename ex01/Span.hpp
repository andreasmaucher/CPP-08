#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    // default constructor
    Span();
    // parameterized constructor
    Span(unsigned int N);
    // copy constructor
    Span(const Span& other);
    // assignment operator
    Span& operator=(const Span& other);
    // destructor
    ~Span();

    // public methods
    void addNumber(int number); // only used for the subject tests
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
        
    // template to add a range of numbers to the span instead of adding one by one
    // can accept any type of iterator (vector, list, array, etc.)
    template<typename Iterator>
    void addNumbersTemplate(Iterator begin, Iterator end) {
        if (numbers.size() + std::distance(begin, end) > N)
            throw std::runtime_error("Not enough space in span");
        // using the vectors own insert method
        numbers.insert(numbers.end(), begin, end);
    }
};

#endif