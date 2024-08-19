/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:28:02 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 16:41:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : creationTimestamp(-1), hasData(false), firstName(""), lastName(""), nickName(""), phoneNumber(""), secret("") {}
Contact::~Contact() {}

/* ----- INPUT RETRIEVAL ----- */

void	Contact::InitContact()
{
	hasData = false;
	GetInputLine("first name", firstName);
	GetInputLine("last name", lastName);
	GetInputLine("nickname", nickName);
	do
	{
		GetInputLine("phone number", phoneNumber);
		if (!IsValidPhoneNumber(phoneNumber))
			std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
	}
	while (!IsValidPhoneNumber(phoneNumber));
	GetInputLine("darkest secret", secret);
	creationTimestamp = time(0);
	hasData = true;

	std::cout << "Contact " << firstName << " " << lastName << " has been created." << std::endl;
	Contact::PrintContact();
}

void	Contact::GetInputLine(std::string prompt, std::string &dest)
{
	std::string input;

	std::cout << "Enter " << prompt << ":\n> ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		if (std::cin.eof()) break;
		std::cout << "Please enter a valid " << prompt << ": ";
		std::getline(std::cin, input);
	}
	dest = input;
}

bool	Contact::IsValidPhoneNumber(const std::string& phoneNumber)
{
	for (char c : phoneNumber)
		if (!isdigit(c) && c != ' ' && c != '+')
			return false;
	return true;
}

/* ----- DATA DISPLAY ----- */

void	Contact::PrintContact()
{
	std::cout << "Name:\t\t" << firstName << " \"" << nickName << "\" " << lastName << std::endl;
	std::cout << "Phone number:\t" << phoneNumber << std::endl;
	std::cout << "Secret:\t\t" << secret << std::endl;
}

// Table Formatting

void	Contact::PrintTableLine(int index)
{
	std::cout << "|";
	Utils::PrintTableCell(std::to_string(index));
	std::cout << "|";
	Utils::PrintTableCell(firstName);
	std::cout << "|";
	Utils::PrintTableCell(lastName);
	std::cout << "|";
	Utils::PrintTableCell(nickName);
	std::cout << "|";
	std::cout << "\n";
}
