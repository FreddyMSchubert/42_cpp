/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:35:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/14 16:41:50 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

#include <chrono> // for timing
#include <iostream>
#include <string>
#include <sstream>

void test(std::vector<int> input)
{
	std::cout << "Before: ";
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	auto start = std::chrono::high_resolution_clock::now();

	PMergeMe p;
	input = p.mergeInsertionSort(input);

	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "After: ";
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	std::cout << "Comparisons: " << p.getComparisonsCount() << std::endl;

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << "Time to process a range of " << input.size() << " elements with std::vector: " << duration << " us" << std::endl;
}

void parse_and_test(char **strs)
{
	std::vector<int> a;

	for (int i = 1; strs[i]; i++)
	{
		try
		{
			a.push_back(std::stoi(strs[i]));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	test(a);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		parse_and_test(argv);
	else
	{
		std::vector<int> a;
		srand(time(NULL));
		int random_amounts = rand() % 25 + 5;
		for (int i = 0; i < random_amounts; i++)
			a.push_back(rand() % 1000);
		test(a);
		return 0;
	}
}
