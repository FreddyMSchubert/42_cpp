/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:10:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 17:57:24 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal
{
	public:
		virtual ~AAnimal() = 0;

		virtual void			makeSound() const = 0;
		virtual std::string		getType() const = 0;

	protected:
		std::string	type;
};