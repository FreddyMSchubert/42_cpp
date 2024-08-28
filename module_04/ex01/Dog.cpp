/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 17:09:28 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "New Dog" << std::endl;
};
Dog::Dog(const Dog&) : Dog()
{
	brain = new Brain();
	std::cout << "Dog copied" << std::endl;
};
Dog::~Dog()
{
	std::cout << "Dog died" << std::endl;
	delete brain;
};
Dog& Dog::operator=(const Dog&)
{
	std::cout << "Reassigned Dog" << std::endl;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain();
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "BARK!" << std::endl;
}