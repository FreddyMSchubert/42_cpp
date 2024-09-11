/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:59:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 00:59:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : data(obj.data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) : data(obj.data) {}
BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(DATA_FILE);
	if (!file.is_open() || !file.good())
		throw std::runtime_error("Error: could not open file " + DATA_FILE);

	std::string line;
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, line.find(DATA_FILE_DELIMITER));
		std::string price = line.substr(line.find(DATA_FILE_DELIMITER) + 1);
		t_date date_struct;
		date_struct.year = std::stoi(date.substr(0, 4));
		date_struct.month = std::stoi(date.substr(5, 2));
		date_struct.day = std::stoi(date.substr(8, 2));
		data[date_struct] = std::stod(price);
	}

	// printing for testing
	for (auto it = data.begin(); it != data.end(); it++)
	{
		std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " : " << it->second << std::endl;
	}
}
