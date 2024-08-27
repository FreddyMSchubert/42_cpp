/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:38:51 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 09:56:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ----- CONSTRUCTS ETC. ----- */

ClapTrap::ClapTrap() : ClapTrap("ClapTrap") {};
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {};
ClapTrap::ClapTrap(ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {};
ClapTrap::~ClapTrap() {};
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
};

/* ----- ACTIONS ----- */

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 1)
	{
		energyPoints--;
		std::cout << name << " attacks target with " << attackDamage << " strength " << std::endl;
	}
	else
	{
		std::cout << name << " is too weak to attack " << target << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << name << " takes " << amount << " damage" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
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
