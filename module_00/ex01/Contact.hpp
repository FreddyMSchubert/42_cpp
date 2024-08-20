/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:37:35 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 13:28:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Utils.hpp"

#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();

		time_t		creationTimestamp;
		bool		hasData;

		void		InitContact();
		void		PrintContact();
		void		PrintTableLine(int index);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;

		void		GetInputLine(std::string prompt, std::string &dest);
		bool		IsValidPhoneNumber(const std::string& phoneNumber);
};
