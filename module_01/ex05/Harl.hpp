/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:25 by freddy            #+#    #+#             */
/*   Updated: 2024/08/21 16:07:22 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
	public:
		static void	complain( std::string level );

	private:
		static void	debug( void );
		static void	info( void );
		static void	warning( void );
		static void	error( void );
};