/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:35:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/14 17:31:11 by fschuber         ###   ########.fr       */
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

	PMergeMe pv;

	auto start = std::chrono::high_resolution_clock::now();
	input = pv.mergeInsertionSort(input);
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "After: ";
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// std::cout << "Comparisons: " << pv.getComparisonsCount() << std::endl;

	std::cout << "Time to process a range of " << input.size() << " elements with std::vector: " << duration << " us" << std::endl;

	PMergeMe pd;
	std::deque<int> inputd(input.begin(), input.end());
	
	auto startd = std::chrono::high_resolution_clock::now();
	inputd = pd.mergeInsertionSort(inputd);
	auto endd = std::chrono::high_resolution_clock::now();

	// std::cout << "Comparisons: " << pd.getComparisonsCount() << std::endl;

	std::cout << "Time to process a range of " << inputd.size() << " elements with std::deque: " << std::chrono::duration_cast<std::chrono::microseconds>(endd - startd).count() << " us" << std::endl;
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
