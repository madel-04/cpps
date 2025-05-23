/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:59 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/17 19:29:12 by madel-va         ###   ########.fr       */
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

        
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif

/*
std::cout << a;
Lo que estás haciendo es imprimir algo (en este caso a) en la consola.
Ese << se llama operador de inserción. Es una forma especial de decir:
"envía esto a la salida estándar (la consola)".

Cuando usas std::cout << a;, el compilador de C++ necesita saber cómo
imprimir ese objeto a.

Esto funciona automáticamente con tipos como:
int, float, char, std::string, etc.
Pero si a es un objeto de una clase que tú has creado (como tu clase Fixed),
entonces el compilador no sabe cómo imprimirlo. Por eso te da este error:
*/