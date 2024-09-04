/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:48:45 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 12:06:15 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "BureaucratExceptions.hpp"
#include "AForm.hpp"

class Bureaucrat
{
	private:
		std::string name;
		int grade;

	public:
		Bureaucrat() = delete;
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat() = default;
		Bureaucrat& operator=(const Bureaucrat &copy);

		std::string getName() const;
		int getGrade() const;
		void setName(std::string name);
		void setGrade(int grade);

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f);