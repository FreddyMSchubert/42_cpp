/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:43:38 by freddy            #+#    #+#             */
/*   Updated: 2024/09/11 12:59:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{
		srand(time(NULL));
		Span sp = Span(10000);
		for (int i = 0; i < 10; i++)
			sp.addNumber(rand() % 50 - 50 / 2);
		std::cout << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{
		Span sp = Span(10);
		sp.addNumber(1);
		sp.addNumber(10);
		sp.addNumber(-2);
		sp.addNumber(9);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{
		Span sp = Span(10);
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i + rand() % 100);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}
