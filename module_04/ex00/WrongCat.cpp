/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:44:26 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 16:56:34 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "New WrongCat" << std::endl;
};
WrongCat::WrongCat(const WrongCat&) : WrongCat() {};
WrongCat::~WrongCat() { std::cout << "WrongCat died" << std::endl; };
WrongCat& WrongCat::operator=(const WrongCat&)
{
	std::cout << "Reassigned WrongCat" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WEOM¡" << std::endl;
}