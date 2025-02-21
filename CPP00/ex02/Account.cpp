# include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;



void Account::_displayTimestamp()
{
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer[80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    std::cout << "[" << buffer << "] ";
}

void	Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus()const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _totalAmount+=deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposits:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{

    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawals:refused" << std::endl;
        return false;
    }
    else
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << ";withdrawals:" << withdrawal;
        _amount -= withdrawal;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return true;
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
	_nbWithdrawals = 0;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
    _totalAmount += initial_deposit;
    _nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}
int Account::getTotalAmount()
{
    return _totalAmount;
}
int Account::getNbDeposits()
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

