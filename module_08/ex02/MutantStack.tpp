/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:51:16 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/11 11:36:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
	this->c = copy.c;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}
