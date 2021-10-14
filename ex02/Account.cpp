// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Oct 14 15:46:59 2021                      //
//                Last update : Thu Oct 14 16:00:32 2021                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

#include <ctime>
#include <iostream>

#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
}

Account::Account( int initial_deposit ):
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) {
	_totalAmount += _amount;
	++_nbAccounts;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	--_nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalAmount;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
	int oldAmount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << oldAmount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int oldAmount;

	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}

	oldAmount = _amount;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;

	++_nbWithdrawals;
	++_totalNbWithdrawals;

	std::cout << "index:" << _accountIndex << ";p_amount:" << oldAmount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t y = std::time(NULL);
	std::tm *local = std::localtime(&y);

	std::cout << std::setw(2) << "[" << (local->tm_year + 1900) << local->tm_mon << local->tm_mday << "_";
	std::cout << local->tm_hour << local->tm_min << local->tm_sec << "] " << std::setw(0);
}
