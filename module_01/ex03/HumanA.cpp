/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:05:51 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:11:25 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Human.hpp"
#include "Weapon.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : Human(name), weapon(weapon) {};
HumanA::~HumanA() {};

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
