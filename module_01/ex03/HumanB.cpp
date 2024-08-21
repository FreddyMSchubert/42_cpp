/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:13:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:19:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Human.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : Human(name), weapon(NULL) {};
HumanB::~HumanB() {};

void HumanB::attack()
{
	std::cout << name;
	if (!weapon)
		std::cout << " wildly flings their arms around, achieving nothing." << std::endl;
	else
		std::cout << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
