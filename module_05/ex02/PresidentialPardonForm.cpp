/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:06:18 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 09:19:23 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ----- CONSTRUCTION ----- */

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy)
{
	this->target = copy.target;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->target = copy.target;
	return *this;
}

/* ----- EXECUTION ----- */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->canBeExecuted(executor))
		return;
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
