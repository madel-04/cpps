/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper function to calculate the area of a triangle using cross product
static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                  (b.getX() * (c.getY() - a.getY())) +
                  (c.getX() * (a.getY() - b.getY())));
    
    // Return absolute value
    if (area < Fixed(0))
        return area * Fixed(-1);
    return area;
}

// BSP function: returns true if point is inside triangle abc
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate area of triangle ABC
    Fixed A = area(a, b, c);
    
    // Calculate area of triangle PAB
    Fixed A1 = area(point, a, b);
    
    // Calculate area of triangle PBC
    Fixed A2 = area(point, b, c);
    
    // Calculate area of triangle PCA
    Fixed A3 = area(point, c, a);
    
    // Check if point is exactly on a vertex or edge
    if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
        return false;
    
    // Check if area of main triangle equals sum of sub-triangles
    // If point is inside, A1 + A2 + A3 should equal A
    return (A == (A1 + A2 + A3));
}
