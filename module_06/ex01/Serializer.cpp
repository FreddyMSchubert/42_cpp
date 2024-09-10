/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:27:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 10:33:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	*Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t *>(ptr);
}

Data		*Serializer::deserialize(void *raw)
{
	return reinterpret_cast<Data *>(raw);
}
