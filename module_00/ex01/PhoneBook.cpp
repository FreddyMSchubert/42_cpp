/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:13:09 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 16:14:00 by fschuber         ###   ########.fr       */
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
