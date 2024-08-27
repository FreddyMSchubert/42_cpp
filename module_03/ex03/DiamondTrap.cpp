/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:28:33 by freddy            #+#    #+#             */
/*   Updated: 2024/08/27 15:31:34 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << name << " woke up just now fraggin'." << std::endl;
};
DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(other.name), ScavTrap(other.name), FragTrap(other.name)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << name << " woke up just now fraggin'." << std::endl;
};
DiamondTrap::~DiamondTrap()
{
	std::cout << name << " drifted out of reality fraggin'." << std::endl;
};