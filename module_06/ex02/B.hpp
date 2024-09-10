/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:00:00 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 11:00:20 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class B : public Base
{
	public:
		B() = default;
		virtual ~B() {};
		B(const B &copy) = default;
		B &operator=(const B &copy) = default;
};
