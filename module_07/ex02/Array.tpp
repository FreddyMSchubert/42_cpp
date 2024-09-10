/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:36:36 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy)
{
	this->_size = copy._size;
	if (!copy.array)
	{
		this->array = NULL;
		return *this;
	}
	this->array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->array[i] = copy.array[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete[] this->array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	this->_size = other._size;
	if (this->array)
		delete[] this->array;
	if (!other.array)
	{
		this->array = NULL;
		return *this;
	}
	this->array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->array[i] = other.array[i];
	return *this;
}

template <typename T>
T	&Array<T>::operator [](unsigned int index) const
{
	if (index >= this->_size)
		throw Array<T>::IndexOutOfRangeException();
	return this->array[index];
}

template <typename T>
const char* Array<T>::IndexOutOfRangeException::what() const throw()
{
	return "Index out of range";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}
