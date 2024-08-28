/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:32:04 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:02:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Generic Animal") {}
Animal::Animal(const Animal &other) : type(other.type) {}
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}
Animal::~Animal() {}

void	Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}
