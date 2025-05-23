/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:59 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/17 19:01:49 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed
{
    public:
        Fixed(); // Default constructor
        Fixed(const Fixed& other); // Copy constructor
        Fixed &operator=(const Fixed &other); // Copy assignment operator
        ~Fixed(); // Destructor
        
        int getRawBits(void) const; // Getter
        void setRawBits(int const raw); // Setter
        
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

#endif

