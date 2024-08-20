// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

public:

	typedef Account		t;

	// these are all just getters
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );

	static void	displayAccountsInfos( void );	// general, non account-specific info display

	Account( int initial_deposit );
	~Account( void );

	// various account operations, refer to tests.cpp for intended output
	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;				// shared accounts count
	static int	_totalAmount;				// shared account balances
	static int	_totalNbDeposits;			// shared total deposits
	static int	_totalNbWithdrawals;		// shared total successful (!) withdrawals

	static void	_displayTimestamp( void );	// displays the [...] thing

	int				_accountIndex;			// #
	int				_amount;				// actual account balance
	int				_nbDeposits;			// deposit count
	int				_nbWithdrawals;			// successful (!) withdrawal count

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
