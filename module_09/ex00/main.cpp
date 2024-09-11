/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:55:35 by fschube           #+#    #+#             */
/*   Updated: 2024/09/12 00:55:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

#define DATA_FILE "data.csv"
#define DATA_FILE_DELIMITER ","
#define INPUT_FILE_DELIMITER " - "

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [inputs file]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	return 0;
}
