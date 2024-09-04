/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:19:30 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 08:49:30 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ----- CONSTRUCTION ----- */

AForm::AForm(std::string name, int signGrade, int execGrade) :
	name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
};
AForm::AForm(const AForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()) {};
AForm::~AForm() {};
AForm& AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return *this;
	this->isSigned = copy.getIsSigned();
	return *this;
}

/* ----- GETTERS & SETTERS ----- */

std::string AForm::getName() const
{ return this->name; }
bool AForm::getIsSigned() const
{ return this->isSigned; }
int AForm::getSignGrade() const
{ return this->signGrade; }
int AForm::getExecGrade() const
{ return this->execGrade; }

/* ----- SIGNING & EXECUTING ----- */

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}

bool AForm::canBeExecuted(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	return true;
}

/* ----- PRINTING ----- */

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << form.getName();
	if (form.getIsSigned())
		out << " was signed";
	else
		out << " is not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return out;
}
void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->canBeExecuted(executor))
		return;
	std::cout << "Form " << this->getName() << " has been executed" << std::endl;
}
