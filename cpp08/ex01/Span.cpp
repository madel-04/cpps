#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

// Calcula el shortest span
int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// Calcula el longest span
int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}

// Tamaño actual
unsigned int Span::size() const
{
    return _numbers.size();
}
