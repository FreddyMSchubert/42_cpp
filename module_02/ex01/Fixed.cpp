/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 11:54:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

/* ----- CONSTRUCTORS ----- */

// ocf
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

// value constructors
Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->val = val << fract_bits;
};
Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->val = static_cast<int>(round(val * (1 << fract_bits)));
};

// ⬆️ regarding that
// we cant just do val << fract_bits, you cant bit-shift a float, cpp rules
// instead we create a factor int by bitshifting 1 (for 9 fract bits, this will be 256)
// the rest is casting to keep things clean

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

int		Fixed::toInt() const
{
	return val >> fract_bits;
};
float	Fixed::toFloat() const
{
	return static_cast<float>(val) / static_cast<float>(1 << fract_bits);
};

/* ----- STREAMS ----- */

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
