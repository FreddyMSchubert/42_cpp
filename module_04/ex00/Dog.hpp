/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:41:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 10:59:26 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();

		void	makeSound() const;
};
