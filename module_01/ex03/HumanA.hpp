/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:00:46 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:07:36 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Human.hpp"
#include "Weapon.hpp"

class HumanA : public Human
{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack( void );
	
	private:
		Weapon& weapon;
};