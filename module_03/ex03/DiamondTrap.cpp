/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:28:33 by freddy            #+#    #+#             */
/*   Updated: 2024/08/27 15:53:33 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), name(name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << name << " woke up just now diamondin'." << std::endl;
};
DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(other.name + "_clap_name"), ScavTrap(other.name + "_scav_name"), FragTrap(other.name + "_frag_name"), name(other.name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << name << " woke up just now diamondin'." << std::endl;
};
DiamondTrap::~DiamondTrap()
{
	std::cout << name << " drifted out of reality diamondin'." << std::endl;
};

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
