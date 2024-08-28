/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:32:04 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 16:54:24 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Generic Animal")
{ std::cout << "New Animal" << std::endl; }
Animal::Animal(const Animal &other) : type(other.type) {}
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}
Animal::~Animal() { std::cout << "Animal died" << std::endl; };

void	Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}
