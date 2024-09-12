/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 01:00:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 05:20:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>

#define DATA_FILE "data.csv"
#define DATA_FILE_DELIMITER ","
#define DATA_FILE_HEADER "date,exchange_rate"
#define INPUT_FILE_DELIMITER " | "
#define INPUT_FILE_HEADER "date | value"

#define DEBUG false

// assuming 31 as the maximum number of days in a month is fine for this exercise
typedef struct s_date
{
	int		year, month, day;

	bool operator<(const s_date& other) const
	{
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		return day < other.day;
	}

	void operator--(int)
	{
		if (day == 1)
		{
			if (month == 1)
			{
				year--;
				month = 12;
				day = 31;
			}
			else
			{
				month--;
				day = 31;
			}
		}
		else
			day--;
	}
}				t_date;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void calculateExchange(const std::string &input_file);

	private:
		std::map<t_date, double> data;

		static t_date parseDate(const std::string &date);
};
