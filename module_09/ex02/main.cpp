/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:35:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 05:49:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main()
{
	PMergeMe p;

	std::vector<int> a;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		a.push_back(rand() % 1000);
	for (int i = 0; i < (int)a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a = p.mergeInsertionSort(a);
	for (int i = 0; i < (int)a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	return 0;
}
