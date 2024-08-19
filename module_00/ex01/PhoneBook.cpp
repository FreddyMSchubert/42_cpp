/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:13:09 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 17:03:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Now I can never unrealize how weird the spelling for the word "Phone" is.

PhoneBook::PhoneBook() : contactsCount(0) {}
PhoneBook::~PhoneBook() {}

/* ----- ADD command ----- */

void	PhoneBook::Add()
{
	int	newContactIndex;
	if (contactsCount >= MAX_CONTACTS_AMOUNT)
		newContactIndex = GetOldestEntry();
	else
		newContactIndex = contactsCount++;
	
	contacts[newContactIndex].InitContact();

	std::cout << "Your Phonebook now has " << contactsCount << " entries.\n";
}

int	PhoneBook::GetOldestEntry()
{
	int	oldestIndex = -1;

	for (int i = 0; i < MAX_CONTACTS_AMOUNT; i++)
	{
		if (!contacts[i].hasData)
			continue;
		if (oldestIndex == -1 || contacts[i].creationTimestamp < contacts[oldestIndex].creationTimestamp)
			oldestIndex = i;
	}

	return oldestIndex;
}

/* ----- SEARCH command ----- */

void	PhoneBook::Search()
{
	// 1. Print Overview Table
	if (contactsCount < 1)
	{
		std::cout << "The phonebook is empty! Add some entries using the ADD command first." << std::endl;
		return;
	}
	PrintTable();

	// 2. Select index of choice
	int index = -1;
	while (true)
	{
		std::cout << "Please input the index of the contact you wish to learn more about:\n> ";
		std::cin >> index;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a numeric index." << std::endl;
			continue;
		}

		if (index < 0 || index >= contactsCount || !contacts[index].hasData)
		{
			std::cout << "Invalid index. Please enter a valid index within the range of existing contacts." << std::endl;
			continue;
		}
	
		break;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// 3. Display detailed contact
	contacts[index].PrintContact();
}

void	PhoneBook::PrintTable()
{
	PrintTableHeader();
	for (int i = 0; i < MAX_CONTACTS_AMOUNT; i++)
		if (contacts[i].hasData)
			contacts[i].PrintTableLine(i);
}

void	PhoneBook::PrintTableHeader()
{
	std::cout << "|";
	Utils::PrintTableCell("Index");
	std::cout << "|";
	Utils::PrintTableCell("First Name");
	std::cout << "|";
	Utils::PrintTableCell("Last Name");
	std::cout << "|";
	Utils::PrintTableCell("Nickname");
	std::cout << "|";
	std::cout << "\n";

	std::cout << "|";
	Utils::PrintTableCell("----------");
	std::cout << "|";
	Utils::PrintTableCell("----------");
	std::cout << "|";
	Utils::PrintTableCell("----------");
	std::cout << "|";
	Utils::PrintTableCell("----------");
	std::cout << "|";
	std::cout << "\n";
}
