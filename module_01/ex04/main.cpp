/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:44:36 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 15:47:55 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect arg setup. It should be \"./sed_sucks <filename> <filterString> <replacementString>.\"" << std::endl;
		exit(-1);
	}

	std::string filename = argv[1];
	std::string filterString = argv[2];
	std::string replaceString = argv[3];

	// READING

	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "Error opening file \"" << filename << "\".";
		exit(-2);
	}
	std::ostringstream buffer;
	std::string inFileString;
	while (getline(inFile, inFileString))
		buffer << inFileString << std::endl;
	inFile.close();
	inFileString = buffer.str();

	// REPLACING

	std::string tempString;
	std::ostringstream outFileStringStream;
	if (filterString.empty())
	{
		outFileStringStream << inFileString;
	}
	else
	{
		for (size_t i = 0; i < inFileString.length(); i++)
		{
			tempString = inFileString.substr(i, filterString.length());
			if (tempString == filterString)
			{
				outFileStringStream << replaceString;
				i += filterString.length() - 1;
			}
			else
			{
				outFileStringStream << inFileString[i];
			}
		}
	}
	std::string outFileString = outFileStringStream.str();

	// WRITING

	std::ofstream outFile(filename + ".replace");
	if (!outFile.is_open())
	{
		std::cerr << "Error opening file \"" << filename << ".replace\".";
		exit(-3);
	}
	outFile << outFileString;
	outFile.close();

	return 0;
}
