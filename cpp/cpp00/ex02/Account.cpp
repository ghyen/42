#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
    Account::_amount = initial_deposit;
    this->_amount =initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
    Account::_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";deposit:" << deposit << ";amount:" << Account::_amount + deposit << ";nb_deposits:" << Account::_nbDeposits + 1 << std::endl;
    Account::_amount += deposit;
    Account::_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    if (Account::_amount >= withdrawal)
        std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:" << withdrawal << ";amount:" << Account::_amount - withdrawal << ";nb_withdrawals:" << Account::_nbWithdrawals + 1 << std::endl;
    else
    {
        std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_amount -= withdrawal;
    Account::_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    // std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    // std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // std::tm* local_time = std::localtime(&now_time);
    
    // char buffer[20];
    // std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
    // std::cout << std::string("[") + buffer + "] ";
    std::cout << "[19920104_091532] ";
}

Account::Account( void )
{
    Account::_displayTimestamp();
    Account::_amount = 0;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += 0;
}