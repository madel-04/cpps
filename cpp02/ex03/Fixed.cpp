/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);    
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

// Increment/decrement operators
Fixed &Fixed::operator++()
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// Static min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
