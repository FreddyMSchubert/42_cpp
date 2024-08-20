/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:13:39 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 13:24:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MAX_CONTACTS_AMOUNT 8

#include "Contact.hpp"
#include "Utils.hpp"

#include <string>
#include <iostream>
#include <iomanip>

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
