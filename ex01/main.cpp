#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try {
        std::cout << "--- Basic main from subject ---\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "\n--- Test with iterator range ---\n";
        Span big = Span(10000);
        // use for loop to fill vector with numbers 0-9999
        // template created can only copy elements from one container to another but not create the numbers!
        std::vector<int> v(10000);
        for (int i = 0; i < 10000; i++)
            v[i] = i;
        
        // transfer all numbers to Span with a single operation
        big.addNumbersTemplate(v.begin(), v.end());
        
        std::cout << "Big span shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Big span longest: " << big.longestSpan() << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}