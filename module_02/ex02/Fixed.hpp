/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 13:09:04 by fschuber         ###   ########.fr       */
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

		// - Mathematical Operators
		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment/Decrement operators
		Fixed& operator++();	// Pre-increment
		Fixed operator++(int);	// Post-increment
		Fixed& operator--();	// Pre-decrement
		Fixed operator--(int);	// Post-decrement

		// Math helper functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(Fixed const& a, Fixed const& b);

	private:
		int					val;
		static const int	fract_bits;
};

// - Streams
std::ostream& operator<<(std::ostream& os, const Fixed& f);