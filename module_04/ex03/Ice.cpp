/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:54:46 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 20:14:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() { _type = "ice"; }
Ice::Ice(const Ice &other) : AMateria(other)
{ _type = other._type; }
Ice::~Ice() {}
Ice& Ice::operator=(const Ice &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string const & Ice::getType() const
{
	return (_type);
}
Ice *Ice::clone() const
{
	return (new Ice(*this));
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
