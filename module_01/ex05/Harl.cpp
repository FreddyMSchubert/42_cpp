/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:56:13 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 16:09:19 by freddy           ###   ########.fr       */
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
	if (level == "DEBUG")
		Harl::debug();
	else if (level == "INFO")
		Harl::info();
	else if (level == "WARNING")
		Harl::warning();
	else if (level == "ERROR")
		Harl::error();
	else
		std::cout << "Invalid level" << std::endl;
}
