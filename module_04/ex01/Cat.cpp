/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 17:39:10 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "New Cat" << std::endl;
};
Cat::Cat(const Cat& other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copied" << std::endl;
};
Cat::~Cat()
{
	std::cout << "Cat died" << std::endl;
	delete brain;
};
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	std::cout << "Reassigned Cat" << std::endl;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}
std::string	Cat::compareBrain(Cat& other) const
{
	if (&brain->ideas[42] == &other.brain->ideas[42])
		return "The same brain";
	else
		return "Different brains";
}
