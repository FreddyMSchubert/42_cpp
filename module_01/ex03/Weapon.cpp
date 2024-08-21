/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:51:28 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 08:55:48 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors

Weapon::Weapon() : type("Unknown") {};
Weapon::Weapon(std::string type) 
{ this->type = type; };
Weapon::~Weapon() {};

// GetSets

std::string	Weapon::getType() const
{ return this->type; };
void	Weapon::setType(std::string type)
{ this->type = type; };