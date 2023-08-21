#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

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
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
    Account::_amount = initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";amount:" << Account::_amount << ";closed" << std::endl;
    Account::_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";p_amount:" << Account::_amount << ";deposit:" << deposit << ";amount:" << Account::_amount + deposit << ";nb_deposits:" << Account::_nbDeposits + 1 << std::endl;
    Account::_amount += deposit;
    Account::_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount( void ) const
{
    
}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
    std::tm t = {};
    std::istringstream ss("2011-Februar-18 23:12:34");
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "[%Y-%b-%d %H:%M:%S]");
    std::cout << std::put_time(&t, "%c") << '\n';
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