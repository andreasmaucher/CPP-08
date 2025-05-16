#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// the entire class is a template so it can work with any type
// inherits from std::stack that uses std::deque as its underlying container
// template classes need their entire implementation in the header file for compilation reasons
template<typename T>
class MutantStack : public std::stack<T>
{
public:
    // default constructor
    MutantStack() : std::stack<T>() {}
    // copy constructor
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    // copy assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    // destructor
    ~MutantStack() {}

    // Iterator typedefs - using the underlying container's iterators
    /*
    There are four iterator types:
        iterator - regular iterator (can read and modify elements)
        const_iterator - constant iterator (can only read elements)
        reverse_iterator - reverse iterator (goes backwards, can read and modify)
        const_reverse_iterator - constant reverse iterator (goes backwards, can only read)
    */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Iterator functions for begin and end and it's reverse versions
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif