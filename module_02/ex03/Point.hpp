/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:56:15 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 17:20:04 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		~Point();
		Point& operator=(const Point &other);

		Fixed getX() const;
		Fixed getY() const;

	private:
		Fixed const x;
		Fixed const y;
};