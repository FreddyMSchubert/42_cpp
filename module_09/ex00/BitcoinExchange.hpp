/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 01:00:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 01:26:00 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>

#define DATA_FILE "data.csv"
#define DATA_FILE_DELIMITER ","
#define DATA_FILE_HEADER "date,exchange_rate"
#define INPUT_FILE_DELIMITER " - "
#define INPUT_FILE_HEADER "date | value"

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
}				t_date;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

	private:
		std::map<t_date, double> data;

};
