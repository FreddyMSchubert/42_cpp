/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:40:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 16:45:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();

		void	announce(void);

	private:
		std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );