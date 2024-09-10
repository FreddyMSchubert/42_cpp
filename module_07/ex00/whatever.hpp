/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:20:06 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 13:23:04 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	&min(T &a, T &b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T	&max(T &a, T &b)
{
	if (a > b)
		return a;
	return b;
}
