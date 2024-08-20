/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:10 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 16:54:07 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "colors.h"

#include <iostream>

#define ZOMBIE_COUNT 26

int	main(void)
{
	std::cout << "The zombies are coming!" << std::endl;
	std::cout << "🧟‍♂️🧟‍♀️🧟‍♂️🧟‍♀️🧟‍♂️🧟‍♀️🧟‍♂️🧟‍♀️🧟‍♂️🧟‍♀️🧟‍♂️🧟‍♀️" << std::endl;

	std::string names[ZOMBIE_COUNT] = {
		"Alice", "Benjamin", "Charlotte", "David", "Eleanor", "Felix", 
		"Grace", "Henry", "Isabella", "James", "Katherine", "Liam", 
		"Mia", "Noah", "Olivia", "Peter", "Quinn", "Rose", "Sebastian", 
		"Theodore", "Ursula", "Victoria", "William", "Xavier", "Yvonne", "Zachary"
	}; // thanks chatgpt

	for (int i = 0; i < ZOMBIE_COUNT; i++)
	{
		if (i % 2 == 0)
		{
			Zombie *zombie = newZombie(names[i]);
			std::cout << ANSI_BOLD_MAGENTA << "HEAP:\t" << ANSI_COLOR_RESET;
			zombie->announce();
			delete zombie;
		}
		else
		{
			std::cout << ANSI_BOLD_RED << "STACK:\t" << ANSI_COLOR_RESET;
			randomChump(names[i]);
		}
	}

	std::cout << "The zombies have all been mercilessly called by YOU when all they wanted was love. You go down in history as a terrible person for typing ./zombie" << std::endl;

	return (0);
}