/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:27:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 03:35:17 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
	// hm....
}
Account::~Account() {}

int	Account::getNbAccounts(void)
{ return (_nbAccounts); }
int	Account::getTotalAmount(void)
{ return (_totalAmount); }
int	Account::getNbDeposits(void)
{ return (_totalNbDeposits); } 
int	Account::getNbWithdrawals(void)
{ return (_totalNbWithdrawals); }