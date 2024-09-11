/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 01:00:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 01:00:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>

typedef struct s_date
{
	int		year;
	int		month;
	int		day;
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
