/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:54:49 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:13:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.h"

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF,
	NEG_INF,
	NONUM, // NAN keyword is reserved
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const & src) = delete;
		ScalarConverter & operator=(ScalarConverter const & rhs) = delete;

	public:
		~ScalarConverter() = default;

		static void	convert(std::string input);
};
