/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:59:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 01:43:37 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ----- CONSTRUCTION ----- */

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : data(obj.data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) { data = obj.data; return *this; }
BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(DATA_FILE);
	if (!file.is_open() || !file.good())
		throw std::runtime_error(std::string("Error: could not open file ") + DATA_FILE);

	std::string line;
	while (std::getline(file, line))
	{
		try
		{
			if (line == DATA_FILE_HEADER || line.empty())
				continue;
			std::string date = line.substr(0, line.find(DATA_FILE_DELIMITER));
			std::string price = line.substr(line.find(DATA_FILE_DELIMITER) + std::string(DATA_FILE_DELIMITER).length());
			t_date date_struct = parseDate(date);
			data[date_struct] = std::stod(price);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error(std::string("Format Error: \"") + line + "\": " + e.what());
		}
	}
}

/* ----- EXCHANGE CALCULATION ----- */

void BitcoinExchange::calculateExchange(const std::string &input_file)
{
	std::ifstream file(input_file);
	if (!file.is_open() || !file.good())
		throw std::runtime_error(std::string("Error: could not open file ") + input_file);

	std::string line;
	while (std::getline(file, line))
	{
		try
		{
			if (line == INPUT_FILE_HEADER || line.empty())
				continue;
			std::string date = line.substr(0, line.find(INPUT_FILE_DELIMITER));
			std::string value = line.substr(line.find(INPUT_FILE_DELIMITER) + std::string(INPUT_FILE_DELIMITER).length());
			t_date date_struct = parseDate(date);
			float valuef = std::stof(value);
			while (data.find(date_struct) == data.end())
				date_struct--;
			double btc = std::stod(value) / data[date_struct];
			std::cout << date << " => " << value << " => " << btc * valuef << std::endl;
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error(std::string("Format Error: \"") + line + "\": " + e.what());
		}
	}
}

/* ----- UTILS ----- */

t_date BitcoinExchange::parseDate(const std::string &date)
{
	t_date date_struct;
	date_struct.year = std::stoi(date.substr(0, 4));
	date_struct.month = std::stoi(date.substr(5, 2));
	date_struct.day = std::stoi(date.substr(8, 2));
	return date_struct;
}
