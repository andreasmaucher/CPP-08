#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept> // for std::runtime_error

template<typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif
