/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:59:29 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 17:10:30 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZOMBIE_HORDE_SIZE 42

int	main()
{
	Zombie* horde = zombieHorde(ZOMBIE_HORDE_SIZE, "Generic Zombie");
	for (int i = 0; i < ZOMBIE_HORDE_SIZE; i++)
		horde[i].announce();
	delete [] horde;

	return 0;
}
