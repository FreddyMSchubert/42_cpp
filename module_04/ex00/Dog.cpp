/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:18:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "New " << type << std::endl;
};
Dog::~Dog() { std::cout << type << " died" << std::endl; };

void	Dog::makeSound() const
{
	std::cout << "BARK!" << std::endl;
}