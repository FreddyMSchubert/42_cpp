/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:25:12 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/28 11:31:04 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &brain);
		Brain& operator=(const Brain& brain);

		std::string ideas[100];
};