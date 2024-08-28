/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:49:50 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 17:19:27 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal *zoo[42];

	for (int i = 0; i < 42; i ++)
	{
		if (i % 2 == 0)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}

	for (int i = 0; i < 42; i ++)
		delete zoo[i];

	Cat *cat = new Cat();
	Cat *cat2 = new Cat(*cat);
	std::cout << cat->compareBrain(*cat2) << std::endl;
	delete cat;
	delete cat2;
}
