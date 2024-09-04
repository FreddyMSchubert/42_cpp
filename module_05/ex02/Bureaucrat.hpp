/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:48:45 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 08:38:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "BureaucratExceptions.hpp"
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string name;
		int grade;

	public:
		Bureaucrat() = delete;
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &copy);

		std::string getName() const;
		int getGrade() const;
		void setName(std::string name);
		void setGrade(int grade);

		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f);