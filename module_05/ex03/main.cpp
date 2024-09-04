/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:08:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 12:30:12 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat boss_man("el jefe", 1);
	Bureaucrat dude("el tipo", 43);
	Bureaucrat slave("el peon", 150);

	Intern formMaker;

	AForm *forms[4] = {
		formMaker.makeForm("shrubbery creation", "home"),
		formMaker.makeForm("robotomy_request", "sad non-robot"),
		formMaker.makeForm("PrEsIdEnTiAl 28384 PaRdOn", "some dude"),
		formMaker.makeForm("nonexistent Form", "some dude"),
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

	for (int i = 0; i < 3; i++)
		delete forms[i];

	return 0;
};