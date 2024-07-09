/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helloWorld.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:49 by freddy            #+#    #+#             */
/*   Updated: 2024/07/09 10:04:28 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_colored(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		std::cout << "\x1b[" << (i % 7 + 31) << "m" << str[i];
		i++;
	}
	std::cout << "\x1b[0m\n";
}

int main()
{
	print_colored("Hello World!");
	print_colored("Freddy here - with my first ever C++ program!");
	print_colored(" ~ and its output is pretty hard to read :P ~ ");
	return 0;
}
