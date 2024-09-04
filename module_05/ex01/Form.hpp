/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:19:44 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 08:22:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Bureaucrat.hpp"
#include "BureaucratExceptions.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;

	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &copy);
		~Form();
		Form& operator=(const Form &copy);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &out, const Form &form);
