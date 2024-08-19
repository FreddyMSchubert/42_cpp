/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:13:39 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 17:04:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACTS_AMOUNT 8

#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		Contact	contacts[MAX_CONTACTS_AMOUNT];
		int		contactsCount;

		void	Add();
		void	Search();

		int		GetOldestEntry();
		void	PrintTable();
		void	PrintTableHeader();
};

#endif