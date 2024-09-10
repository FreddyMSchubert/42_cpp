/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:29:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 13:35:25 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T & x)
{
	std::cout << x << " ";
}

template <typename T>
void half(T & x)
{
	x /= 2;
}

int main()
{
	int intArray[5] = {1, 2, 3, 4, 5};
	float floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[5] = {"one", "two", "three", "four", "five"};

	std::cout << "Int array: ";
	iter(intArray, 5, print);
	std::cout << std::endl;
	iter(intArray, 5, half);
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << "Float array: ";
	iter(floatArray, 5, print);
	std::cout << std::endl;
	iter(floatArray, 5, half);
	iter(floatArray, 5, print);
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(stringArray, 5, print);
	std::cout << std::endl;

	iter(stringArray, 0, print);
	iter(stringArray, -1, print);

	return 0;
};
