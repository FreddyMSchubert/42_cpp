/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:18:23 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 12:25:21 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : FragTrap("FragTrap") {};
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << name << " woke up just now fraggin'." << std::endl;
};
FragTrap::FragTrap(FragTrap& other) : ClapTrap(other.name)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << name << " woke up just now fraggin'." << std::endl;
};
FragTrap::~FragTrap()
{
	std::cout << name << " drifted out of reality fraggin'." << std::endl;
};

void FragTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		return ;
	if (energyPoints > 1)
	{
		energyPoints--;
		std::cout << name << " attacks " << target << " with " << attackDamage << " strength & while fraggin'" << std::endl;
	}
	else
	{
		std::cout << name << " is too weak to attack " << target << " even while fraggin'" << std::endl;
	}
}
void FragTrap::highFivesGuys()
{
	if (hitPoints <= 0)
		return ;
	std::cout << name << " brings all the boys to the yard - and gives them a high five with schmagges!" << std::endl;
}
