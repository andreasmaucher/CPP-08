#include "MutantStack.hpp"
#include <iostream>
#include <list>

/*
std::stack container is one of the only containers that is not iterable
*/

int main()
{
    std::cout << "--- Test from subject ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "- printing values -" << std::endl;
    while (it != ite)
    {
        std::cout << "value: " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << "\n--- Testing with list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++lst_it;
    --lst_it;
    std::cout << "- printing values -" << std::endl;
    while (lst_it != lst_ite)
    {
        std::cout << "value: " << *lst_it << std::endl;
        ++lst_it;
    }
    return (0);
}