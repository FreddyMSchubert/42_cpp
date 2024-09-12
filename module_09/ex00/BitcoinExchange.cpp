/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:59:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 02:27:13 by freddy           ###   ########.fr       */
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
			if (!line.find(DATA_FILE_DELIMITER))
				throw std::runtime_error("Delimiter missing: " + line);

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
			unsigned int delimiterPos = line.find(INPUT_FILE_DELIMITER);
			if (line.find(INPUT_FILE_DELIMITER) == std::string::npos)
			{
				std::cerr << "bad input => " << line << std::endl;
				continue;
			}

			std::string date = line.substr(0, delimiterPos);
			t_date date_struct;
			try { date_struct = parseDate(date); }
			catch(const std::exception& e) { std::cerr << e.what() << std::endl; continue; }

			std::string value = line.substr(delimiterPos + std::string(INPUT_FILE_DELIMITER).length());
			if (value.empty())
			{
				std::cerr << "bad input => " << line << std::endl;
				continue;
			}
			double valuef = std::stof(value);
			if (valuef < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (valuef > std::numeric_limits<int>::max())
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			while (data.find(date_struct) == data.end())
				date_struct--;
			double btc = data[date_struct];

			if (DEBUG)
				std::cout << date << " => Parsed value: " << valuef << "; Exchange Rate: " << btc << " => " << btc * valuef << std::endl;
			else
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
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Error: invalid date format => \"" + date + "\"");

	t_date date_struct;

	date_struct.year = std::stoi(date.substr(0, 4));
	date_struct.month = std::stoi(date.substr(5, 2));
	date_struct.day = std::stoi(date.substr(8, 2));

	if (date_struct.month < 1 || date_struct.month > 12 || date_struct.day < 1 || date_struct.day > 31)
		throw std::runtime_error("Error: bad input => " + date);

	return date_struct;
}
