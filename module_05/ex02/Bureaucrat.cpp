/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:48:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 11:37:06 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- CONSTRUCTION ----- */

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->setName(name);
	this->setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->setName(copy.getName());
	this->setGrade(copy.getGrade());
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	this->setName(copy.getName());
	this->setGrade(copy.getGrade());
	return *this;
}

/* ----- GETTERS & SETTERS ----- */
// add range exceptions here

std::string Bureaucrat::getName() const
{ return this->name; }
int Bureaucrat::getGrade() const
{ return this->grade; }
void Bureaucrat::setName(std::string name)
{ this->name = name; }
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

/* ----- FORM SIGNING ----- */

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		if (form.getIsSigned())
		{
			std::cout << this->getName() << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
			return ;
		}
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because" << e.what() << std::endl;
	}
}
