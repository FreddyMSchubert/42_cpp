/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:21:57 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 16:23:18 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	for (int i = 0; i < 500; i++)
	{
		if (i % 5 == 0)
			Harl().complain("DEBUG");
		if (i % 7 == 0)
			Harl().complain("INFO");
		if (i % 11 == 0)
			Harl().complain("WARNING");
		if (i % 13 == 0)
			Harl().complain("ERROR");
	}
}
