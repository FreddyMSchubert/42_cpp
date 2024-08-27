/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:38:51 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 12:25:09 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ----- CONSTRUCTS ETC. ----- */

ClapTrap::ClapTrap() : ClapTrap("ClapTrap") {};
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << name << " woke up just now." << std::endl;
};
ClapTrap::ClapTrap(ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << name << " woke up just now." << std::endl;
};
ClapTrap::~ClapTrap()
{
	std::cout << name << " drifted out of reality." << std::endl;
};
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
};

/* ----- ACTIONS ----- */

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		return ;
	if (energyPoints > 1)
	{
		energyPoints--;
		std::cout << name << " attacks " << target << " with " << attackDamage << " strength " << std::endl;
	}
	else
	{
		std::cout << name << " is too weak to attack " << target << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		return ;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << name << " takes " << amount << " damage" << std::endl;
	if (hitPoints == 0)
		std::cout << name << " fell asleep... forever." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
		return ;
	if (energyPoints > 1)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << name << " repairs itself by " << amount << " hit points" << std::endl;
	}
	else
	{
		std::cout << name << " is too weak to repair itself" << std::endl;
	}
}
