/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:58:50 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/10 10:59:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
	public:
		Base() = default;
		virtual ~Base() {};
		Base(const Base &copy) = default;
		Base &operator=(const Base &copy) = default;
};
