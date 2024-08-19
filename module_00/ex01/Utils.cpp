/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:21:51 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/19 16:24:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void	Utils::PrintTableCell(std::string data)
{
	if (data.length() > 10)
		std::cout << data.substr(0, 9) << ".";
	std::cout << std::setw(10) << std::right << data;
}
