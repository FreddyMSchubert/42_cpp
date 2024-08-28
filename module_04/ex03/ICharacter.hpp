/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:03:25 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 19:44:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual	std::string const & getName() const = 0;
		virtual	void equip(AMateria *m) = 0;
		virtual	void unequip(int idx) = 0;
		virtual	void use(int idx, ICharacter& target) = 0;
};
