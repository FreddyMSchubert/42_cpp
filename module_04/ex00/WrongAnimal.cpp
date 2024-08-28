/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:32:04 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 16:56:10 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic WrongAnimal")
{ std::cout << "New WrongAnimal" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}
WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal died" << std::endl; };

void	WrongAnimal::makeSound() const
{
	std::cout << "¿¿¿" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}
