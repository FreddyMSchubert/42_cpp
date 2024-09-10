/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:31:42 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 10:31:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	uintptr_t *serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << deserialized->s1 << std::endl;
	std::cout << deserialized->n << std::endl;
	std::cout << deserialized->s2 << std::endl;

	return 0;
}