/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:23:22 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/26 13:46:39 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

/* ----- CONSTRUCTORS ----- */

// ocf
Fixed::Fixed()
{ val = 0; };
Fixed::Fixed(const Fixed &other)
{ *this = other; }
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
};
Fixed::~Fixed() {};

// value constructors
Fixed::Fixed(const int val)
{
	this->val = val << fract_bits;
};
Fixed::Fixed(const float val)
{
	this->val = static_cast<int>(roundf(val * (1 << fract_bits)));
};

/* ----- GETTERS & SETTERS ----- */

int		Fixed::getRawBits(void) const
{ return val; }
void	Fixed::setRawBits(int const raw)
{ val = raw; }

int		Fixed::toInt() const
{ return val >> fract_bits; };
float	Fixed::toFloat() const
{ return static_cast<float>(val) / static_cast<float>(1 << fract_bits); };

/* ----- MATHEMATICAL OPERATORS */

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{ return this->getRawBits() > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const
{ return this->getRawBits() < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const
{ return this->getRawBits() >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const
{ return this->getRawBits() <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const
{ return this->getRawBits() == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const
{ return this->getRawBits() != other.getRawBits(); }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{ return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const
{ return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const
{ return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const
{
	if (other == Fixed(0))
	{
		std::cerr << "Error: Attempted division by 0" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement operators
// Post increment operators take an int as an arg. Why? Ask Bjarne i guess.
Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}
Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

/* ----- MATH HELPER FUNCTIONS ----- */

Fixed& Fixed::min(Fixed& a, Fixed& b)
{ return a < b ? a : b; }
const Fixed& Fixed::min(Fixed const& a, Fixed const& b)
{ return a < b ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b)
{ return a > b ? a : b; }
const Fixed& Fixed::max(Fixed const& a, Fixed const& b)
{ return a > b ? a : b; }

/* ----- STREAMS ----- */

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
