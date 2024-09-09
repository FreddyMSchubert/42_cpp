/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:56:13 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/06 09:36:44 by freddy           ###   ########.fr       */
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
	runTest("-42");
	runTest("-");
	runTest(".");
	runTest(",");
	runTest("");
	runTest("0");
	runTest("-0");
	runTest("0000000");
	runTest("420");
	runTest("483a649");
	runTest("ß");
	runTest("apple");
	runTest("42.0f"); //
	runTest("42.f"); //
	runTest(".3f"); //
	runTest(".f");
	runTest("123.123f"); //
	runTest("123.123f.");
	runTest("123123f.");
	runTest("123123.f"); //
	runTest("123.123f.23");
	runTest("123.123.23");
	runTest("123.123.0");
	runTest("123..23");
	runTest("123.123.1f");
	runTest("123.1f1");
	runTest("f");
	runTest("35.3F");
	runTest("\n"); //
	runTest("\t"); //
	runTest("\v"); //
	runTest("\r"); //
	runTest("29.3");
	runTest("29. 3");
	runTest(" ");
	runTest("                         ");
	runTest("nan");
	runTest("nanf");
	runTest("inf");
	runTest("inff");
	runTest("+inff");
	runTest("+inf");
	runTest("-inf");
	runTest("-inff");
	runTest(std::to_string(std::numeric_limits<char>::max()));
	runTest(std::to_string(static_cast<int>(std::numeric_limits<char>::max()) + 1));
	runTest(std::to_string(std::numeric_limits<char>::min())); //
	runTest(std::to_string(static_cast<int>(std::numeric_limits<char>::min()) - 1)); //
	runTest(std::to_string(std::numeric_limits<int>::max()));
	runTest(std::to_string(static_cast<long long>(std::numeric_limits<int>::max()) + 1LL));
	runTest(std::to_string(std::numeric_limits<int>::min()));
	runTest(std::to_string(static_cast<long long>(std::numeric_limits<int>::min()) - 1LL));
	runTest(std::to_string(std::numeric_limits<float>::max()) + 'f'); //
	runTest(std::to_string(static_cast<double>(std::numeric_limits<float>::max()) + 1.0) + 'f'); // 
	runTest(std::to_string(std::numeric_limits<float>::min()) + 'f'); //
	runTest(std::to_string(static_cast<double>(std::numeric_limits<float>::min()) - 1.0) + 'f'); //
	runTest(std::to_string(std::numeric_limits<double>::max()));
	runTest(std::to_string(std::numeric_limits<double>::max() + 1.0));
	runTest(std::to_string(std::numeric_limits<double>::min()));
	runTest(std::to_string(std::numeric_limits<double>::min() - 1.0));
}
