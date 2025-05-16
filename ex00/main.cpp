#include "Easyfind.hpp"
#include <iostream>
#include <vector> // dynamic array container
#include <list>

/*
vector: like a dynamic arra with automatic resizing, continguous memory, any element can be accessed
directly by index, handles memory allocation automatically
*/

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 2);    // [0, 2, 4, 6, 8]

    std::cout << "Vector contains: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Test easyfind with existing value
    try {
        std::vector<int>::iterator result = easyfind(vec, 4);
        std::cout << "Found value 4 at position: " 
                  << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test easyfind with non-existing value
    try {
        std::vector<int>::iterator result = easyfind(vec, 5);
        std::cout << "Found value 5 at position: " 
                  << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}