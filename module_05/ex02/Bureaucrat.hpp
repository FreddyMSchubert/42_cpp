/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:48:45 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:48:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "BureaucratExceptions.hpp"
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

		void setGrade(int grade);

	public:
		Bureaucrat() = delete;
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat() = default;
		Bureaucrat& operator=(const Bureaucrat &copy);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f);