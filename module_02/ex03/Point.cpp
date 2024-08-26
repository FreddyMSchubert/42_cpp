/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:22 by freddy            #+#    #+#             */
/*   Updated: 2024/08/26 17:04:04 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {};
Point::Point(float x, float y) : x(x), y(y) {};
Point::Point(Point& other) : x(other.getX()), y(other.getY()) {};
Point::~Point() {};
Point& Point::operator=(const Point &other)
{
	// Data is not updateable, so = shouldn't do anything
	(void) other;
	return *this;
};

Fixed Point::getX() const
{ return x; }
Fixed Point::getY() const
{ return y; }