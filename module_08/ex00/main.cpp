/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:36:38 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 20:43:20 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	{
		std::vector<int> vec;
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
			vec.push_back(rand() % 25);

		std::cout << "Vector contents: ";
		for (int num : vec)
			std::cout << num << " ";
		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
		{
			try
			{
				auto it = easyfind(vec, rand() % 25);
				std::cout << "Element found: " << *it << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}

	std::cout << std::endl;

	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(4);
		lst.push_back(3);
		lst.push_back(2);
		lst.push_back(1);
		lst.push_back(0);

		std::cout << "List contents: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		bool foundmatch = false;
		int nonMatchesFound = 0;
		while (!foundmatch)
		{
			try
			{
				int nextTest = rand() % 250;
				std::cout << "Test " << nextTest << ":\t";
				auto it = easyfind(lst, nextTest);
				std::cout << "Element found: " << *it << std::endl;
				foundmatch = true;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				nonMatchesFound++;
			}
		}

		std::cout << "Non-matches found: " << nonMatchesFound << std::endl;
	}

	return 0;
};
