/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:33:10 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 20:26:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
		if (other.source[i])
			source[i] = other.source[i]->clone();
		else
			source[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
		if (other.source[i])
			source[i] = other.source[i]->clone();
		else
			source[i] = NULL;
	}
	return *this;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!source[i])
		{
			source[i] = materia;
			return ;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materia" << std::endl;
	std::cout << "Deleting materia" << std::endl;
	delete materia;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i]->getType() == type)
		{
			return source[i]->clone();
		}
	}
	return NULL;
}