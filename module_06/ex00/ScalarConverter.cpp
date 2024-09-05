/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:54:41 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/05 11:08:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ----- IDENTIFICATION ----- */

static bool	isChar(std::string input)
{
	return input.length() == 1 && !std::isdigit(input[0]);
}
static bool	isInt(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && !std::isdigit(input[i]) && input[i] != '-' && input[i] != '+')
			return false;
		if (!std::isdigit(input[i]))
			return false;
	}
	if (input[0] == '-' || input[0] == '+')
		if (input.length() == 1)
			return false;
	return true;
}
static bool	isFloat(std::string input)
{
	bool dotEncountered = false;
	bool numberEncountered = false;
	if (input.back() != 'f')
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]))
			numberEncountered = true;
		if (i == 0 && !std::isdigit(input[i]) && input[i] != '.' && input[i] != '-' && input[i] != '+')
			return false;
		if (input[i] == '.')
		{
			if (dotEncountered)
				return false;
			dotEncountered = true;
		}
		else if (!std::isdigit(input[i]))
			return false;
	}
	return numberEncountered;
}
static bool	isDouble(std::string input)
{
	bool dotEncountered = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && !std::isdigit(input[i]) && input[i] != '.' && input[i] != '-' && input[i] != '+')
			return false;
		if (input[i] == '.')
		{
			if (dotEncountered)
				return false;
			dotEncountered = true;
		}
		else if (!std::isdigit(input[i]))
			return false;
	}
	return input.length() > 0 + dotEncountered;
}
static bool	isPosInf(std::string input)
{ return input == "+inf" || input == "+inff" || input == "inf" || input == "inff"; }
static bool	isNegInf(std::string input)
{ return input == "-inf" || input == "-inff"; }
static bool	isNan(std::string input)
{ return input == "nan"; }

/* ----- PRINTING ----- */

void	printDataType(ScalarType type)
{
	switch (type)
	{
		case CHAR:
			std::cout << "char" << std::endl;
			break;
		case INT:
			std::cout << "int" << std::endl;
			break;
		case FLOAT:
			std::cout << "float" << std::endl;
			break;
		case DOUBLE:
			std::cout << "double" << std::endl;
			break;
		case INF:
			std::cout << "inf" << std::endl;
			break;
		case NEG_INF:
			std::cout << "-inf" << std::endl;
			break;
		case NONUM:
			std::cout << "nan" << std::endl;
			break;
		case INVALID:
		default:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}

void	printTypes(std::string c, std::string i, std::string f, std::string d, ScalarType type)
{
	std::cout << "Identified type: ";
	printDataType(type);
	std::cout << "char  : " << c << std::endl;
	std::cout << "int   : " << i << std::endl;
	std::cout << "float : " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* ----- MAIN CONVERSION ----- */

static ScalarType	getType(std::string input)
{
	if (input.empty())
		return INVALID;
	typedef bool(*TypeFinders)(const std::string);
	TypeFinders finders[] = {isChar, isInt, isFloat, isDouble, isPosInf, isNegInf, isNan};
	for (size_t i = 0; i < 9; i++)
		if (finders[i](input))
			return static_cast<ScalarType>(i);
	return INVALID;
}

void	ScalarConverter::convert(std::string input)
{
	ScalarType type = getType(input);
	switch (type)
	{
		case CHAR:
			printTypes(input, std::to_string(static_cast<int>(input[0])), std::to_string(static_cast<float>(input[0])), std::to_string(static_cast<double>(input[0])), type);
			break;
		case INT:
			printTypes(std::to_string(static_cast<char>(std::stoi(input))), input, std::to_string(static_cast<float>(std::stoi(input))), std::to_string(static_cast<double>(std::stoi(input))), type);
			break;
		case FLOAT:
			printTypes(std::to_string(static_cast<char>(std::stof(input))), std::to_string(static_cast<int>(std::stof(input))), input, std::to_string(static_cast<double>(std::stof(input))), type);
			break;
		case DOUBLE:
			printTypes(std::to_string(static_cast<char>(std::stod(input))), std::to_string(static_cast<int>(std::stod(input))), std::to_string(static_cast<float>(std::stod(input))), input, type);
			break;
		case INF:
			printTypes("impossible", "impossible", "inff", "inf", type);
			break;
		case NEG_INF:
			printTypes("impossible", "impossible", "-inff", "-inf", type);
			break;
		case NONUM:
			printTypes("impossible", "impossible", "nanf", "nan", type);
			break;
		case INVALID:
		default:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}
