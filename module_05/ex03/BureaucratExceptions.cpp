/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:05:35 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 09:07:55 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucratExceptions.hpp"

const char *GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char *GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

const char *FormNotSignedException::what() const noexcept
{
	return "Form is not signed";
}