/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:49:50 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:13:07 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;



	std::cout << "\n\n\n";
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();

	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wi->getType() << " " << std::endl << std::endl;

	wmeta->makeSound();
	wi->makeSound();

	delete wmeta;
	delete wi;

	return 0;
}
