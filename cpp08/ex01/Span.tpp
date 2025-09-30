#ifndef SPAN_TPP
#define SPAN_TPP

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
    {
        if (_numbers.size() >= _maxSize)
            throw std::runtime_error("Span is full");
        _numbers.push_back(*it);
    }
}

#endif
