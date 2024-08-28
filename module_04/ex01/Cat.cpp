/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:32:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "New " << type << std::endl;
};
Cat::~Cat()
{
	std::cout << type << " died" << std::endl;
	delete brain;
};

void	Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}