/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 16:54:59 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "New Cat" << std::endl;
};
Cat::Cat(const Cat&) : Cat() {};
Cat::~Cat() { std::cout << "Cat died" << std::endl; };
Cat& Cat::operator=(const Cat&)
{
	std::cout << "Reassigned Cat" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}