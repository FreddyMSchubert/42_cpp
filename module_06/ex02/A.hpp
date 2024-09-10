/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:59:43 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 11:00:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class A : public Base
{
	public:
		A() = default;
		virtual ~A() {};
		A(const A &copy) = default;
		A &operator=(const A &copy) = default;
};
