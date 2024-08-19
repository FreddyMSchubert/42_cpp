/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:37:35 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 13:51:09 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <ctime>
#include <string>
#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();

		time_t		creationTimestamp;
		bool		hasData;

		void		InitContact();
		void		PrintContact();

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;

		void		GetInputLine(std::string prompt, std::string *dest);
		bool		IsValidPhoneNumber(const std::string& phoneNumber);
};

#endif