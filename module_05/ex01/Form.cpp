/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:19:30 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 12:11:58 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ----- CONSTRUCTION ----- */

Form::Form(std::string name, int signGrade, int execGrade) :
	name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
};
Form::Form(const Form &copy) : Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade()) {};

/* ----- GETTERS & SETTERS ----- */

std::string Form::getName() const
{ return this->name; }
bool Form::getIsSigned() const
{ return this->isSigned; }
int Form::getSignGrade() const
{ return this->signGrade; }
int Form::getExecGrade() const
{ return this->execGrade; }

/* ----- SIGNING ----- */

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}

/* ----- PRINTING ----- */

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName();
	if (form.getIsSigned())
		out << " was signed";
	else
		out << " is not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return out;
}