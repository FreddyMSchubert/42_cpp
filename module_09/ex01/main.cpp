/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:32:20 by freddy            #+#    #+#             */
/*   Updated: 2024/09/12 03:34:52 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/WisdomSky/reverse-polish-notation-js-parser

#include <iostream>
#include <sstream>
#include <stack>

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

void printCalculation(std::vector<std::string>& tokens)
{
	for (int i = 0; i < (int)tokens.size(); i++)
		std::cout << tokens[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2 || std::string(argv[1]).empty())
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	std::vector<std::string> tokens;

	std::istringstream iss(argv[1]);
	std::string arg;
	while (iss >> arg)
		tokens.push_back(arg);

	std::stack<char> rev_operators;
	std::stack<double> rev_numbers;

	if (PRINT_CALCULATION)
		printCalculation(tokens);

	try
	{
		bool operationApplied = true;
		while (operationApplied)
		{
			operationApplied = false;
			for (int i = 0; i < (int)tokens.size(); ++i)
			{
				if (tokens.size() <= 2)
					break ;
				if (isOperator(tokens[i]) && tokens.size() > 2)
				{
					double num1 = std::stod(tokens[i - 2]);
					double num2 = std::stod(tokens[i - 1]);
					double result = applyOperation(num1, num2, tokens[i][0]);

					tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
					tokens.insert(tokens.begin() + i - 2, std::to_string(result));

					operationApplied = true;
					if (PRINT_CALCULATION && tokens.size() > 1)
						printCalculation(tokens);

					break;
				}
			}
		}
		if (tokens.size() != 1) throw std::runtime_error("Invalid expression");
		std::cout << "Result: " << tokens[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
