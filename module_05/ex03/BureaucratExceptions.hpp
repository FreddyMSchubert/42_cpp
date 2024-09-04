/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:01:10 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 09:07:41 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		const char *what() const noexcept override;
};
class GradeTooLowException : public std::exception
{
	public:
		const char *what() const noexcept override;
};
class FormNotSignedException : public std::exception
{
	public:
		const char *what() const noexcept override;
};