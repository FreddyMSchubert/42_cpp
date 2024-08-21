/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:19:40 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:37:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>

int	main()
{
	std::cout << "A wild bokoblin appears!" << std::endl;
	std::cout << "His girlfriend is right behind him." << std::endl;

	Weapon club = Weapon("crude spiked club");
	Weapon club2 = Weapon("basic boko bow");
	HumanA bokoblin("Bokoblin", club);
	HumanA bokoblin2("Bokoblina", club2);
	bokoblin.attack();

	std::cout << "Link is here to save the day!" << std::endl;

	Weapon slingshot = Weapon("slingshot");
	HumanB link("Link");
	link.setWeapon(slingshot);
	link.attack();

	std::cout << "Bokoblina's bow shatters & she switches to a spiked boko club." << std::endl;

	club2.setType("spiked boko bow");

	bokoblin.attack();
	bokoblin2.attack();

	std::cout << "Link pulls out his master sword!" << std::endl;
	Weapon sword = Weapon("sword");
	link.setWeapon(sword);

	link.attack();
	link.attack();

	std::cout << "The bokoblins turn into purple smoke while Link polishes his sword." << std::endl;
}
