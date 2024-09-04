/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:15:58 by freddy            #+#    #+#             */
/*   Updated: 2024/09/04 12:36:25 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*Intern::makeShrubberyCreationForm(std::string const &target)
{ return (new ShrubberyCreationForm(target)); }
AForm	*Intern::makeRobotomyRequestForm(std::string const &target)
{ return (new RobotomyRequestForm(target)); }
AForm	*Intern::makePresidentialPardonForm(std::string const &target)
{ return (new PresidentialPardonForm(target)); }

std::string	normalizeString(const std::string raw)
{
	std::ostringstream oss;
	for (size_t i = 0; i < raw.size(); i++)
		if (std::isalpha(raw[i]))
			oss << static_cast<char>(std::tolower(raw[i]));
	return oss.str();
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	AForm* (Intern::*formCreators[3])(std::string const &target) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	std::string normalizedFormName = normalizeString(formName);
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (normalizedFormName == formNames[i])
			{
				std::cout << "Intern creates " << formName << std::endl;
				return (this->*formCreators[i])(target);
			}
		}
		std::cout << "Form " << formName << " (id " << normalizedFormName <<") not found" << std::endl;
		return nullptr;
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern could not create " << formName << " due to " << e.what() << std::endl;
	}
	return nullptr;
}
