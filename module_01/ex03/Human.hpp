/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:49:59 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/21 10:26:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Human
{
	public:
		Human(std::string name);
		~Human();

		virtual void attack( void ) = 0;
	
	protected:
		std::string name;
};