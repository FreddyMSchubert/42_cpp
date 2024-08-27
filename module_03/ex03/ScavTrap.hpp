/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:57:54 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 15:31:57 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& other);
		~ScavTrap() override;

		void attack(const std::string& target) override;
		void guardGate();
};