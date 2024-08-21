/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:44:36 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:57:04 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

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

	std::ifstream inFile("example_input.txt");
	if (!inFile.is_open())
	{
		std::cerr << "Error opening file \"" << filename << "\".";
		exit(-2);
	}
	std::string currLine;
	while (getline(inFile, currLine))
		std::cout << currLine << std::endl;
	inFile.close();

	// WRITING

	std::ofstream outFile("example_output.txt");
	if (!outFile.is_open())
	{
		std::cerr << "Error opening file \"" << filename << "\".";
		exit(-3);
	}
	outFile << "Welcome to file handling in CPP! It's exactly like in C, I think I'll manage." << std::endl;
	outFile << "A wild baobab tree appears! It has no attacks, relax." << std::endl;
	outFile.close();

	return 0;
}
