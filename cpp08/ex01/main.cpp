#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // Test masivo
    std::srand(std::time(0));
    Span big(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(rand());

    big.addNumbers(numbers.begin(), numbers.end());
    std::cout << "Big Span shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Big Span longest: " << big.longestSpan() << std::endl;

    return 0;
}
