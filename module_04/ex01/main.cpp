/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:49:50 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:50:00 by fschuber         ###   ########.fr       */
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
}
