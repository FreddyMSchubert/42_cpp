/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 13:36:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int	main()
{
	std::cout << "Hello world! Full fixed number implementation time!" << std::endl;

	Fixed		a;
	Fixed const	b (Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "Continueing with non-subject tests now!" << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "A is larger: " << (a > b) << std::endl;
	std::cout << "A is smaller: " << (a < b) << std::endl;
	std::cout << "A is larger or equal: " << (a >= b) << std::endl;
	std::cout << "A is smaller or equal: " << (a <= b) << std::endl;
	std::cout << "A is equal to a: " << (a == a) << std::endl;

	std::cout << "Plus: " << (a + b) << std::endl;
	std::cout << "Minus: " << (a - b) << std::endl;
	std::cout << "Times: " << (a * b) << std::endl;
	std::cout << "Division: " << (a / b) << std::endl;

	std::cout << "That was fun! Now, let's dicide by 0 and see whether we encounter the singularity." << std::endl;
	std::cout << "42 / 0 = " << (Fixed(42) / Fixed(0)) << std::endl;
	std::cout << (3.0f / 0.0f) << std::endl;
	std::cout << Fixed(3.0f / 0.0f) << std::endl;

	return 0;
}
