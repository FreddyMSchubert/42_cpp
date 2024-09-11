/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:50:54 by freddy            #+#    #+#             */
/*   Updated: 2024/09/11 08:43:09 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}
Span::Span(Span const &other) : _n(other._n), _numbers(other._numbers) {}
Span &Span::operator=(Span const &other)
{
	if (this == &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _n)
		throw std::runtime_error("Span is full");
	_numbers.insert(n);
}
int Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Span is too short, you donut!");

	std::multiset<int>::iterator it = _numbers.begin();
	int prev = *it;
	int diff = std::numeric_limits<int>::max();

	for (++it; it != _numbers.end(); ++it)
	{
		int currDiff = *it - prev;
		if (currDiff < diff)
			diff = currDiff;
		prev = *it;
	}
	return diff;
}
int Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Span is too short");
	return *(_numbers.rbegin()) - *(_numbers.begin());
}
