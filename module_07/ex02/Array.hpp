/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:46 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:21 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& other);
		T	&operator[](unsigned int index) const;

		unsigned int size() const;

	private:
		T*				array;
		unsigned int	_size;

	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw() override;
	};
};

#include "Array.tpp"
