/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:35:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/13 14:40:54 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main()
{
	PMergeMe p;

	std::vector<int> a;
	srand(time(NULL));
	int random_amounts = rand() % 15 + 5;
	std::cout << "Random amounts: " << random_amounts << std::endl;
	for (int i = 0; i < random_amounts; i++)
		a.push_back(rand() % 1000);
	for (int i = 0; i < (int)a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a = p.mergeInsertionSort(a);
	for (int i = 0; i < (int)a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Comparisons: " << p.getComparisonsCount() << std::endl;

	return 0;
}
