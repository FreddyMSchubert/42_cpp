/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 16:55:17 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "New Dog" << std::endl;
};
Dog::Dog(const Dog&) : Dog() {};
Dog::~Dog() { std::cout << "Dog died" << std::endl; };
Dog& Dog::operator=(const Dog&)
{
	std::cout << "Reassigned Dog" << std::endl;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "BARK!" << std::endl;
}