/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:43:24 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 15:55:22 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap gorgoblov("gorgoblov");
	DiamondTrap shymaldur("shymaldur");

	shymaldur.highFivesGuys();
	gorgoblov.guardGate();
	shymaldur.whoAmI();
	gorgoblov.whoAmI();
	gorgoblov.attack("42 paris, an inferior campus to 42 Heilbronn, ");
	shymaldur.attack("gorgoblov");
	gorgoblov.takeDamage(4);
	gorgoblov.beRepaired(3);
	gorgoblov.attack("shymaldur");
	shymaldur.takeDamage(42);
	gorgoblov.beRepaired(1);

	return 0;
}
