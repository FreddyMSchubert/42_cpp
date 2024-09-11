/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:51:02 by freddy            #+#    #+#             */
/*   Updated: 2024/09/11 12:56:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <set>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &other);
		~Span() = default;
		Span &operator=(Span const &other);

		void addNumber(int n);
		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _n)
				throw std::out_of_range("Span is full");
			_numbers.insert(begin, end);
		}
		int shortestSpan();
		int longestSpan();
	
	private:
		unsigned int		_n;
		std::multiset<int>	_numbers;
};
