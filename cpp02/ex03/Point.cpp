/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0)
{
}

// Constructor with parameters
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

// Copy assignment operator
Point &Point::operator=(const Point &other)
{
    // Since _x and _y are const, we cannot change them after initialization
    // This assignment operator cannot do anything meaningful
    // but we need it for Orthodox Canonical Form
    (void)other; // To avoid unused parameter warning
    return *this;
}

// Destructor
Point::~Point()
{
}

// Getters
Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}
