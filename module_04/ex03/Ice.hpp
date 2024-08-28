/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:53:46 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 18:58:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(std::string const & type);
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);
		virtual ~Ice();

		std::string const & getType() const;

		Ice* clone() const = 0;
		void use(ICharacter& target);
};