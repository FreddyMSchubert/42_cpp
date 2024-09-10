/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:54:41 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 09:47:09 by fschuber         ###   ########.fr       */
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
		if (i == 0)
			continue;
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
	if (input.back() != 'f')
		return false;
	for (size_t i = 0; i < input.length() - 1; i++)
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
	return true;
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
{ return input == "nan" || input == "nanf"; }

/* ----- FORMATTING ------ */

static std::string	trim(std::string input)
{
	std::ostringstream result;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(input[i])))
			result << input[i];
	}
	return result.str();
}

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
	std::cout << "TYPE  : ";
	printDataType(type);
	std::cout << ANSI_BACKGROUND_RED << "char  : ";
	if (c.length() == 1)
		std::cout << "'" << c << "'";
	else
		std::cout << c;
	std::cout << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_BACKGROUND_GREEN << "int   : " << i << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_BACKGROUND_YELLOW << "float : " << f << "f" << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_BACKGROUND_BLUE << "double: " << d << ANSI_COLOR_RESET << std::endl;
	std::cout << ANSI_COLOR_RESET;
}

/* ----- MAIN CONVERSION ----- */

static ScalarType	getType(std::string input)
{
	if (input.empty())
		return INVALID;
	typedef bool(*TypeFinders)(const std::string);
	TypeFinders finders[] = {isChar, isInt, isFloat, isDouble, isPosInf, isNegInf, isNan};
	for (size_t i = 0; i < 7; i++)
		if (finders[i](input))
			return static_cast<ScalarType>(i);
	std::cout << "Couldn't find matching data type." << std::endl;
	return INVALID;
}

static bool	isWithinLimits(std::string input, ScalarType type)
{
	// check against int max etc
	try
	{
		if (type == INT)
			std::stoi(input);
		else if (type == FLOAT)
			std::stof(input);
		else if (type == DOUBLE)
			std::stod(input);
		return true;
	}
	catch (std::exception & e)
	{
		return false;
	}
	return true;
}

void	ScalarConverter::convert(std::string input)
{
	input = trim(input);
	ScalarType type = getType(input);
	int asciiValue;
	std::string charRepresentation;
	double num;
	if (!isWithinLimits(input, type))
	{
		std::cout << "Input out of range" << std::endl;
		return ;
	}
	try
	{
		switch (type)
		{
			case CHAR:
				charRepresentation = (input[0] >= 33 && input[0] <= 126) ? std::string(1, input[0]) : "Not displayable";
				printTypes(charRepresentation, std::to_string(static_cast<int>(input[0])), std::to_string(static_cast<float>(input[0])), std::to_string(static_cast<double>(input[0])), type);
				break;
			case INT:
				asciiValue = std::stoi(input);
				charRepresentation = (asciiValue >= 33 && asciiValue <= 126) ? std::string(1, static_cast<char>(asciiValue)) : "Not displayable";
				printTypes(charRepresentation, input, std::to_string(static_cast<float>(std::stoi(input))), std::to_string(static_cast<double>(std::stoi(input))), type);
				break;
			case FLOAT:
			case DOUBLE:
				num = type == FLOAT ? std::stof(input) : std::stod(input);
				asciiValue = static_cast<int>(num);
				charRepresentation = (asciiValue >= 33 && asciiValue <= 126) ? std::string(1, static_cast<char>(asciiValue)) : "Not displayable";
				printTypes(charRepresentation, std::to_string(static_cast<int>(num)), std::to_string(static_cast<float>(num)), std::to_string(num), type);
				break;
			case INF:
				printTypes("impossible", "impossible", "inf", "inf", type);
				break;
			case NEG_INF:
				printTypes("impossible", "impossible", "-inf", "-inf", type);
				break;
			case NONUM:
				printTypes("impossible", "impossible", "nan", "nan", type);
				break;
			case INVALID:
			default:
				std::cout << "Invalid input" << std::endl;
				break;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Conversion failed" << std::endl;
	}
}
