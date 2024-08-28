/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:01:17 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 19:01:25 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(std::string const & type);
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		virtual ~Cure();

		std::string const & getType() const;

		Cure* clone() const = 0;
		void use(ICharacter& target);
};