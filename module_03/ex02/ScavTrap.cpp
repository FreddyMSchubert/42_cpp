/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:05:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 12:24:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ScavTrap("ScavTrap") {};
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << name << " woke up just now scavvin'." << std::endl;
};
ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other.name)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << name << " woke up just now scavvin'." << std::endl;
};
ScavTrap::~ScavTrap()
{
	std::cout << name << " drifted out of reality scavvin'." << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		return ;
	if (energyPoints > 1)
	{
		energyPoints--;
		std::cout << name << " attacks " << target << " with " << attackDamage << " strength & while scavvin'" << std::endl;
	}
	else
	{
		std::cout << name << " is too weak to attack " << target << " even while scavvin'" << std::endl;
	}
}
void ScavTrap::guardGate()
{
	std::cout << name << " has entered gate keeper mode" << std::endl;
}
