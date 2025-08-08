/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed(); // Default constructor
        Fixed( const int value );
        Fixed( const float value );
        Fixed(const Fixed& other); // Copy constructor
        Fixed &operator=(const Fixed &other); // Copy assignment operator
        ~Fixed(); // Destructor
        
        int getRawBits(void) const; // Getter
        void setRawBits(int const raw); // Setter

        float toFloat( void ) const;
        int toInt( void ) const;

        // Comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // Arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // Increment/decrement operators
        Fixed &operator++(); // Pre-increment
        Fixed operator++(int); // Post-increment
        Fixed &operator--(); // Pre-decrement
        Fixed operator--(int); // Post-decrement

        // Static min/max functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
