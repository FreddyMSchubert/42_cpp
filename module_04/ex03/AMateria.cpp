/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:47:05 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 19:38:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// What even is a Materia? You're missing an L there, buddy.
// No wait I looked it up, it's a Final Fantasy thing. I never got around to playing those games.

AMateria::AMateria() : _type("mysterious, wobbly materia") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(const AMateria &other) : _type(other._type) {}
AMateria::~AMateria() {}
AMateria& AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}
void AMateria::use(ICharacter& target)
{
	std::cout << "Used " << _type << " on " << target.getName() << std::endl;
}