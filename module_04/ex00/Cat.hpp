/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:41:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 10:59:21 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();

		void	makeSound() const;
};
