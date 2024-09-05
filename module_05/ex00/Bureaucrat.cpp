/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:48:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:46:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- CONSTRUCTION ----- */

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName())
{
	this->setGrade(copy.getGrade());
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	this->setGrade(copy.getGrade());
	return *this;
}

/* ----- GETTERS & SETTERS ----- */
// add range exceptions here

std::string Bureaucrat::getName() const
{ return this->name; }
int Bureaucrat::getGrade() const
{ return this->grade; }
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

/* ----- GRADE MODIFICATIONS ----- */

void Bureaucrat::incrementGrade()
{ this->setGrade(this->getGrade() - 1); }
void Bureaucrat::decrementGrade()
{ this->setGrade(this->getGrade() + 1); }

/* ----- PRINTING / LOGGING ----- */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return os;
}
