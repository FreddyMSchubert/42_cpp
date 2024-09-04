/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:08:03 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/04 08:51:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Andrea", 1);
	Bureaucrat b("Bobby", 150);
	Bureaucrat c("Carl", 75);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	Form f("Form1", 1, 1);
	std::cout << f << std::endl;
	Form g("Form2", 149, 150);
	std::cout << g << std::endl;
	Form h("Form3", 76, 75);
	std::cout << h << std::endl;

	a.signForm(f);
	b.signForm(g);
	c.signForm(h);

	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;

	return 0;
};