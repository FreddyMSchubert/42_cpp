/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:11:43 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:19:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Human.hpp"
#include "Weapon.hpp"

class HumanB : public Human
{
	public:
		HumanB(std::string name);
		~HumanB();
		void attack( void );
		void setWeapon( Weapon& weapon );

	private:
		Weapon *weapon;
};