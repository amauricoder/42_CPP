/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:50:32 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/31 18:08:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime> //time()
#include <iostream> //cout endl
#include <iomanip> //setw()

//Static member variables are shared across all instances of the class. 
//They must be defined outside the class because they exist independently 
//of any object and are not automatically allocated with the class itself.
int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @category Constructor
 * @brief Init the object with the initial_deposit value
 * and prints some informations following the .log given example.
 */
Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts ++;
	_totalAmount += _amount;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" 
	<< std::endl;
}

/**
 * @category Destructor
 */
Account::~Account(void)
{
    _nbAccounts--;
	Account::_displayTimestamp();
    std::cout 
		<< "index:" << _accountIndex
   		<< ";amount:" << _amount
		<< ";closed"
	<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/**
 * @brief Display the timestamp
 * @attention Useful link -> https://www.w3schools.com/cpp/cpp_date.asp
 */
void    Account::_displayTimestamp(void)
{
	//std::cout << "Display Time Stamp" << std::endl;
	// Get the current time as a time_t object
    time_t timestamp;
    time(&timestamp);

	// Convert to local time structure
    std::tm *localTime = localtime(&timestamp);
	std::cout << "[" << 1900 + localTime->tm_year << std::setw(2) << std::setfill('0')
              << 1 + localTime->tm_mon << std::setw(2) << std::setfill('0')
              << localTime->tm_mday << "_" << std::setw(2) << std::setfill('0')
              << localTime->tm_hour << std::setw(2) << std::setfill('0')
              << localTime->tm_min << std::setw(2) << std::setfill('0')
              << localTime->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout 
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	old_amount = _amount;

	_amount += deposit;
	_nbDeposits ++;
	_totalNbDeposits ++;
	_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << old_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	old_amount = _amount;

	Account::_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << old_amount << ";";
	if (old_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals ++;
		_totalNbWithdrawals ++;
		_totalAmount -= withdrawal;
		std::cout
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return (true);
	}
	std::cout 
		<< "withdrawal:refused"
	<< std::endl;
	return (false);
}

int	Account::checkAmount(void) const
{
	return (this->_totalAmount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
	<< std::endl;
}


