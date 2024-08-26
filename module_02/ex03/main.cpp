/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:21:17 by freddy            #+#    #+#             */
/*   Updated: 2024/08/26 17:36:47 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(6, 0);
	Point c(0, 6);

	Point pm1(-1, -1);
	Point p0(0, 0);
	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 3); // on the hypothenuse
	Point p4(4, 4);

	std::cout << "Point P-1 is inside the triangle ABC: " << bsp(a, b, c, pm1) << std::endl;
	std::cout << "Point P0 is inside the triangle ABC: " << bsp(a, b, c, p0) << std::endl;
	std::cout << "Point P1 is inside the triangle ABC: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Point P2 is inside the triangle ABC: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "Point P3 is inside the triangle ABC: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "Point P4 is inside the triangle ABC: " << bsp(a, b, c, p4) << std::endl;
	return 0;
}