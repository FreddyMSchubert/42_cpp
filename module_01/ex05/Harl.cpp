/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:56:13 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 16:21:05 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{ std::cout << "DEGUB" << std::endl; }
void	Harl::info()
{ std::cout << "IFNO" << std::endl; }
void	Harl::warning()
{ std::cout << "WARNIGN" << std::endl; }
void	Harl::error()
{ std::cout << "ERORR" << std::endl; }

void	Harl::complain( std::string level )
{
	void (Harl::*levelPtr[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	const std::string levelStr[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levelStr[i])
		{
			(this->*levelPtr[i])();
			break;
		}
	}
}
