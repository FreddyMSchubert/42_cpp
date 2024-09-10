/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:27:34 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 10:32:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct Data
{
	std::string	s1;
	int			n;
	std::string	s2;
} Data;


class Serializer
{
	private:
		Serializer() = default;
		~Serializer() = default;
		Serializer(const Serializer &other) = default;
		Serializer &operator=(const Serializer &other) = default;

	public:
		static uintptr_t	*serialize(Data *ptr);
		static Data			*deserialize(void *raw);
};
