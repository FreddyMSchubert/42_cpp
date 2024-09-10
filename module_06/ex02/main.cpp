/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:01:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 11:16:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base	*generate(void)
{
	int randomNumber = rand();
	if (randomNumber % 3 == 0)
		return new A();
	else if (randomNumber % 3 == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Object is neither A, B or C." << std::endl;
}

void	identify(Base &r)
{
	bool identified = false;

	Base base;
	try
	{
		base = dynamic_cast<A&>(r);
		std::cout << "A" << std::endl;
		identified = true;
	}
	catch(const std::exception& e) {}

	try
	{
		base = dynamic_cast<B&>(r);
		std::cout << "B" << std::endl;
		identified = true;
	}
	catch(const std::exception& e) {}

	try
	{
		base = dynamic_cast<C&>(r);
		std::cout << "C" << std::endl;
		identified = true;
	}
	catch(const std::exception& e) {}

	if (!identified)
		std::cout << "Object is neither A, B or C." << std::endl;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *random = generate();
		if (!random) continue;

		std::cout << "Identifying by pointer" << std::endl;
		identify(random);

		std::cout << "identifying by reference" << std::endl;
		identify(*random);

		delete random;
		std::cout << "---------------" << std::endl;
	}
}
