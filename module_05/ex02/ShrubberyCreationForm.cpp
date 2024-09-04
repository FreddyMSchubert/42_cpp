/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:06:18 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 12:03:08 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ----- CONSTRUCTION ----- */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy)
{
	this->target = copy.target;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->target = copy.target;
	return *this;
}

/* ----- EXECUTION ----- */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->canBeExecuted(executor))
		return;
	std::string filename = this->target + "_shrubbery";
	std::ofstream outFile(filename, std::ios::app);
	if (!outFile.is_open() || outFile.fail())
	{
		std::cerr << "Error opening file \"" << filename << "\".";
		exit(-2);
	}
	outFile << "o" << std::endl << "|" << std::endl << std::endl;
	outFile.close();
}
