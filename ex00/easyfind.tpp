#ifndef EASYFIND_TPP
#define EASYFIND_TPP

// T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter
// no i++ since find is doing the iteration automatically
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator i = std::find(container.begin(), container.end(), value);
    if (i == container.end())
        throw std::runtime_error("Value not found in container");
    return i;
}

#endif
