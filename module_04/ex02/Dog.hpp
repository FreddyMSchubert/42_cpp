/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:41:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 17:57:40 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();
		Dog& operator=(const Dog& dog);

		void	makeSound() const;
		std::string		getType() const;

	private:
		Brain *brain;
};
