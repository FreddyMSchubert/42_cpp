/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:56:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:09:11 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	runTest(std::string test)
{
	std::cout << "Testing: \"" << test << "\"" << std::endl;
	ScalarConverter::convert(test);
	std::cout << std::endl;
}

int	main()
{
	runTest("42");
	runTest("-");
	runTest(".");
	runTest(",");
	runTest("");
	runTest("0");
	runTest("420");
	runTest("2147483647");
	runTest("2147483648");
	runTest("-2147483648");
	runTest("-2147483649");
	runTest("-2147483a649");
	runTest("ß");
	runTest("42.0f");
	runTest("42.f");
	runTest(".3f");
	runTest(".f");
	runTest("123.123f");
	runTest("123.123283848829329239389238923f");
	runTest("1232939402838928928923293892389.123f");
	runTest("f");
	runTest("35.3F");
	runTest("\n");
	runTest("\t");
	runTest("\v");
	runTest("\r");
	runTest("29.3");
	runTest("29. 3");
	runTest("29.3283892989238928923892389238923");
	runTest("2930489283048293923804080403403.28");
	runTest(" ");
	runTest("nan");
	runTest("nanf");
	runTest("inf");
	runTest("inff");
	runTest("+inff");
	runTest("+inf");
	runTest("-inf");
	runTest("-inff");
}
