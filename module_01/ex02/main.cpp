/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:15:42 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 17:21:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "PTR ADDR: " << ptr << "\n";
	std::cout << "REF ADDR: " << &ref << "\n";
	std::cout << "PTR VALUE: " << *ptr << "\n";
	std::cout << "REF VALUE: " << ref << "\n";

	return 0;
}
