/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:06:18 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 09:19:23 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ----- CONSTRUCTION ----- */

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy)
{
	this->target = copy.target;
}

/* ----- EXECUTION ----- */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->canBeExecuted(executor))
		return;
	std::cout << "*drilling noises* ";
	(rand() % 2 ? std::cout << this->target << " has been robotomized successfully" : std::cout << this->target << " robotomization failed") << std::endl;
}