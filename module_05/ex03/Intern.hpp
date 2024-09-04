/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:14:44 by freddy            #+#    #+#             */
/*   Updated: 2024/09/04 12:28:10 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <sstream>

class Intern
{
	public:
		Intern() = default;
		Intern(const Intern&) = default;
		~Intern() = default;
		Intern& operator=(const Intern&) = default;

		AForm* makeForm(std::string formName, std::string target);

	private:
		AForm	*makeShrubberyCreationForm(std::string const &target);
		AForm	*makeRobotomyRequestForm(std::string const &target);
		AForm	*makePresidentialPardonForm(std::string const &target);
};
