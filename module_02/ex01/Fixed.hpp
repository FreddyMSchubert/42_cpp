/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 11:53:39 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class Fixed
{
	public:
		// - Constructors
		// ocf
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		// value constructors
		Fixed(const int val);
		Fixed(const float val);

		// - Getters & Setters
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		int					toInt() const;
		float				toFloat() const;

	private:
		int					val;
		static const int	fract_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);