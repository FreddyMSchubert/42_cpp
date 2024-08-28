/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:39:21 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 20:08:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		AMateria *tmp = src->createMateria("ice");
		std::cout << tmp->getType() << std::endl;
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		std::cout << tmp->getType() << std::endl;

		delete src;
	}

	{
		ICharacter *me = new Character("me");
		me->equip(new Ice());
		me->equip(new Cure());
		me->equip(new Cure());
		me->equip(new Cure());
		me->equip(new Cure());
		me->use(0, *me);
		me->use(1, *me);
		std::cout << "unequipping 0" << std::endl;
		me->unequip(0);
		me->use(0, *me);
		me->use(1, *me);
		std::cout << "unequipping 1" << std::endl;
		me->unequip(1);
		me->use(0, *me);
		me->use(1, *me);
		std::cout << "my name is " << me->getName() << std::endl;
		delete me;
	}

	return 0;
}