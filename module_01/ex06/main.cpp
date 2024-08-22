/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:30:04 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 16:39:37 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter [\"DEBUG\" | \"INFO\" | \"WARNING\" | \"ERROR\"]" << std::endl;
		return (1);
	}

	int level = -1;
	const std::string levelStr[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levelStr[i])
		{
			level = i;
			break;
		}
	}

	switch (level)
	{
		case 0:
			std::cout << "DEGUB" << std::endl;
		case 1:
			std::cout << "IFNO" << std::endl;
		case 2:
			std::cout << "WARNIGN" << std::endl;
		case 3:
			std::cout << "ERORR" << std::endl;
			break;
		default:
			std::cout << "CUNFOSED MUMBLING" << std::endl;
			return (1);
	}

	return (0);
}
