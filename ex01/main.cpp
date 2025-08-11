#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

#include "Span.h"

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(5);
        int arr[] = {6, 3, 17, 9, 11};
        std::vector<int> numbers(arr, arr + 5);
        sp.addNumbers(numbers.begin(), numbers.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(0);
        try {
            sp.addNumber(0);
        } catch (const std::logic_error& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (const std::logic_error& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (const std::logic_error& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    {
        std::vector<int> numbers(100000);
        for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
            numbers[i] = i;
        }
        Span sp = Span(static_cast<unsigned int>(numbers.size()));
        sp.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return 0;
}
