/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:19:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 08:44:42 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;
#include "BureaucratExceptions.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
	
	protected:
		bool canBeExecuted(Bureaucrat const & executor) const;

	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &copy);
		virtual ~AForm() = default;
		AForm& operator=(const AForm &copy) = delete;

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &out, const AForm &AForm);
