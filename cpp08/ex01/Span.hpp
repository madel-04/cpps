#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:

    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    // Agregar números
    void addNumber(int number);

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);

    // Calcular spans
    int shortestSpan();
    int longestSpan();

    // Para tests
    unsigned int size() const;
};

#include "Span.tpp" // Opcional si implementamos templates fuera
#endif
