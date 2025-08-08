/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public:
        Point(); // Default constructor
        Point(const float x, const float y); // Constructor with parameters
        Point(const Point &other); // Copy constructor
        Point &operator=(const Point &other); // Copy assignment operator
        ~Point(); // Destructor
        
        // Getters
        Fixed getX(void) const;
        Fixed getY(void) const;
        
    private:
        Fixed const _x;
        Fixed const _y;
};

// BSP function declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
