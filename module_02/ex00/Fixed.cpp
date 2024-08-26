/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 13:47:06 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

/* ----- CONSTRUCTORS ----- */

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
};
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
};
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

/* ----- GETTERS & SETTERS ----- */

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return val;
}
void	Fixed::setRawBits(int const raw)
{
	val = raw;
}
