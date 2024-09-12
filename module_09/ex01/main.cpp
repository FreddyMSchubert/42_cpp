/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:32:20 by freddy            #+#    #+#             */
/*   Updated: 2024/09/12 04:52:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/WisdomSky/reverse-polish-notation-js-parser

#include <iostream>
#include <sstream>
#include <deque>

#define PRINT_CALCULATION false

bool isOperator(const std::string& token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

double applyOperation(double num1, double num2, char op)
{
	switch (op)
	{
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': 
			if (num2 == 0) throw std::runtime_error("Division by zero");
			return num1 / num2;
		default: throw std::runtime_error("Invalid operator");
	}
}

void printCalculation(std::deque<std::string>& tokens)
{
	for (const auto& token : tokens)
		std::cout << token << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2 || std::string(argv[1]).empty())
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::deque<std::string> tokens;

	std::istringstream iss(argv[1]);
	std::string arg;
	while (iss >> arg)
		tokens.push_back(arg);

	if (PRINT_CALCULATION)
		printCalculation(tokens);

	try
	{
		bool operationApplied = true;
		while (operationApplied)
		{
			operationApplied = false;
			for (auto it = tokens.begin(); it != tokens.end(); ++it)
			{
				if (tokens.size() <= 2)
					break ;
				if (isOperator(*it) && std::distance(tokens.begin(), it) >= 2)
				{
					auto num1 = std::stod(*(it - 2));
					auto num2 = std::stod(*(it - 1));
					double result = applyOperation(num1, num2, (*it)[0]);

					*(it - 2) = std::to_string(result);
					tokens.erase(it - 1, it + 1);

					operationApplied = true;
					if (PRINT_CALCULATION && tokens.size() > 1)
						printCalculation(tokens);

					break;
				}
			}
		}
		if (tokens.size() != 1) throw std::runtime_error("Invalid expression");
		std::cout << "Result: " << tokens.front() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
