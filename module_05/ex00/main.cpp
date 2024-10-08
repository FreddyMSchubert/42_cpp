/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:08:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:47:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Alex", 1);
	Bureaucrat b("Bob", 150);
	Bureaucrat c("Charlie", 75);

	try
	{
		Bureaucrat d("Dennis", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	try
	{
		a.incrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
	try
	{
		b.incrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
	try
	{
		c.incrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	a.decrementGrade();
	b.decrementGrade();
	c.decrementGrade();

	std::cout << std::endl;

	try
	{
		a.decrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
	try
	{
		b.decrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
	try
	{
		c.decrementGrade();
	}
	catch (const std::exception& e)
	{ std::cerr << e.what() << '\n'; }

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
};