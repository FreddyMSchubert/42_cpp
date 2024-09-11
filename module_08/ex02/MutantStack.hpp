/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:11 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/11 11:38:37 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() = default;
		~MutantStack() = default;
		MutantStack(const MutantStack &copy) = default;
		MutantStack &operator=(const MutantStack &copy);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
