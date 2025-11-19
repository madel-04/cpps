#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _n(0) {}
// Constructor sin parámetros   

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _n(n) {}
// Constructor con tamaño unsigned int n

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._n]()), _n(other._n)
{
    for (size_t i = 0; i < _n; ++i)
        _array[i] = other._array[i];
}
// Constructor de copia

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        _n = other._n;
        _array = new T[_n]();
        for (size_t i = 0; i < _n; ++i)
            _array[i] = other._array[i];
    }
    return *this;
}
// Operador de asignación

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}
// Destructor

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _n)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}
// Sobrecarga del operador [] para acceso a elementos por índice

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _n)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}
// Sobrecarga del operador [] para acceso a elementos por índice (const)    

template <typename T>
size_t Array<T>::size() const
{
    return _n;  
}
// Método size() que devuelve el tamaño del array

#endif