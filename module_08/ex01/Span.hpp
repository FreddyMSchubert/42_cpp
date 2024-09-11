/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:51:02 by freddy            #+#    #+#             */
/*   Updated: 2024/09/10 20:56:47 by freddy           ###   ########.fr       */
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
		int shortestSpan();
		int longestSpan();
	
	private:
		unsigned int		_n;
		std::multiset<int>	_numbers;
};
