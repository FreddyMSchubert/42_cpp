/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:12:39 by freddy            #+#    #+#             */
/*   Updated: 2024/08/26 17:35:28 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Given points ABC of the Triangle and P as the point to check,
// if the area of the triangle ABC is equal to the sum of the areas of the triangles ABP, ACP, and BCP,
// then the point P is inside the triangle ABC.

Fixed	calcArea(Point const a, Point const b, Point const c)
{
	Fixed area = Fixed(
		a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY())
	) / Fixed(2);
	if (area < 0)
		area = area * Fixed(-1);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return calcArea(a, b, c) == calcArea(a, b, point) + calcArea(a, point, c) + calcArea(point, b, c);
}
