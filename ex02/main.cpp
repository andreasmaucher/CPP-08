#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // Test with MutantStack
    std::cout << "=== Testing MutantStack ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test copy constructor and assignment
    std::cout << "\n=== Testing copy and assignment ===" << std::endl;
    MutantStack<int> s(mstack);
    std::cout << "Copied stack size: " << s.size() << std::endl;

    // Test with std::list for comparison
    std::cout << "\n=== Testing std::list ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Top: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "Size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through list:" << std::endl;
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();

    ++lst_it;
    --lst_it;

    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }

    return 0;
}