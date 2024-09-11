/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:57:00 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/11 11:52:21 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> lstack;

	mstack.push(5);
	mstack.push(17);
	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << mstack.top() << std::endl;

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		int r = rand() % 1000;
		mstack.push(r);
		lstack.push_back(r);
	}

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator itl = lstack.begin();

	while (it != ite)
	{
		std::cout << *it << " - " << *itl << std::endl;
		++it;
		++itl;
	}

	std::stack<int> s(mstack);
	return 0;
}
