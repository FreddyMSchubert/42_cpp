/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:17:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 20:28:46 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}
Character::Character(const Character &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}
Character& Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	return *this;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full, cannot equip more materia" << std::endl;
	std::cout << "Deleting materia" << std::endl;
	delete m;
}
void Character::unequip(int idx)
{
	if (!inventory[idx])
		return ;
	delete inventory[idx];
	inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
		inventory[idx]->use(target);
}