/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:19:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "New " << type << std::endl;
};
WrongCat::~WrongCat() { std::cout << type << " died" << std::endl; };

void	WrongCat::makeSound() const
{
	std::cout << "WEOM¡" << std::endl;
}