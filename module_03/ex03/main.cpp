/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:43:24 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/27 12:21:26 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap gorgoblov;
	FragTrap shymaldur("shymaldur");

	shymaldur.highFivesGuys();
	gorgoblov.attack("42 paris, an inferior campus to 42 Heilbronn, ");
	shymaldur.attack("gorgoblov");
	gorgoblov.takeDamage(4);
	gorgoblov.beRepaired(3);
	gorgoblov.attack("shymaldur");
	shymaldur.takeDamage(42);
	gorgoblov.beRepaired(1);

	return 0;
}
