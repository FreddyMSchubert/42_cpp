/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:00:30 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 11:00:56 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class C : public Base
{
	public:
		C() = default;
		virtual ~C() {};
		C(const C &copy) = default;
		C &operator=(const C &copy) = default;
};
