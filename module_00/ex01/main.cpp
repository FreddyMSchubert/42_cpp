/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:47:16 by freddy            #+#    #+#             */
/*   Updated: 2024/08/20 12:50:06 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void PrintAvailableCommands()
{
	std::cout << "Available Commands:\n";
	std::cout << " - ADD to add a contact\n";
	std::cout << " - SEARCH to display a specific contact\n";
	std::cout << " - EXIT to quit the program :(";
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Error: No arguments expected." << std::endl;
		return -1;
	}

	PhoneBook phoneBook;

	PrintAvailableCommands();

	// Program Loop
	while (true)
	{
		std::string input;
		std::cout << "Enter command:\n> ";

		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
			continue ;

		if (input == "ADD")
			phoneBook.Add();
		else if (input == "SEARCH")
			phoneBook.Search();
		else if (input == "EXIT" || std::cin.eof())
			break;
		else
		{
			std::cout << "Error: " << "\"" << input << "\" is not a valid command!" << std::endl;
			PrintAvailableCommands();
		}
	}

	return 0;
}
