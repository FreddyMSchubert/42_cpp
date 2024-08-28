/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:00:02 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 19:16:07 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() { _type = "cure"; }
Cure::Cure(const Cure &other) { _type = other._type; }
Cure::~Cure() {}
Cure& Cure::operator=(const Cure &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string const & Cure::getType() const
{
	return (_type);
}
Cure *Cure::clone() const
{
	return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
