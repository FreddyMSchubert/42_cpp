/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:08:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:54:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss_man("el jefe", 1);
	Bureaucrat dude("el tipo", 43);
	Bureaucrat slave("el peon", 150);

	AForm *forms[3] = {
		new RobotomyRequestForm("sad non-robot"),
		new ShrubberyCreationForm("home"),
		new PresidentialPardonForm("some dude")
	};

	for (int i = 0; i < 3; i++)
	{
		std::cout << *forms[i] << std::endl;
		slave.executeForm(*forms[i]);
		dude.executeForm(*forms[i]);
		boss_man.executeForm(*forms[i]);
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << *forms[i] << std::endl;
		slave.signForm(*forms[i]);
		dude.signForm(*forms[i]);
		boss_man.signForm(*forms[i]);
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << *forms[i] << std::endl;
		slave.executeForm(*forms[i]);
		dude.executeForm(*forms[i]);
		boss_man.executeForm(*forms[i]);
	}

	std::cout << std::endl;

	for (int i = 0; i < 42; i++)
		boss_man.executeForm(*forms[0]);

	for (int i = 0; i < 3; i++)
		delete forms[i];

	return 0;
};