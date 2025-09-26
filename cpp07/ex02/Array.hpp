#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T*      _array;
        size_t  _n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        // Sobrecargas del operador [] para acceso a elementos por índice

        size_t size() const;
};


#include "Array.tpp"

#endif