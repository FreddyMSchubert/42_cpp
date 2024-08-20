/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:27:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:01 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

/* ----- CONSTRUCTORS & DESTRUCTORS ----- */

Account::Account(int initial_deposit)
{
	// Data Initialization
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// Hello message
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account()
{
	// Goodbye message
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
	_nbAccounts--;
}

/* ----- GETTERS & SETTERS ----- */

int	Account::getNbAccounts()
{ return (_nbAccounts); }
int	Account::getTotalAmount()
{ return (_totalAmount); }
int	Account::getNbDeposits()
{ return (_totalNbDeposits); } 
int	Account::getNbWithdrawals()
{ return (_totalNbWithdrawals); }

/* ----- GENERAL FUNCTIONS ----- */

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

/* ----- ACCOUNT ACTIONS ----- */

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
				<< ";deposit:" << deposit << ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal;

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

// Data Retrievers

int	Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

/* ----- UTILS ----- */

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(nullptr);
	std::tm *tm = std::localtime(&t);

	std::cout << "[" << (tm->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << (tm->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << tm->tm_mday << "_"
				<< std::setw(2) << std::setfill('0') << tm->tm_hour
				<< std::setw(2) << std::setfill('0') << tm->tm_min
				<< std::setw(2) << std::setfill('0') << tm->tm_sec << "] ";
}
