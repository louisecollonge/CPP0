#define BLUE	"\033[94m"
#define RESET	"\033[0m"

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbDeposits);}
int	Account::checkAmount( void ) const { return (_amount); } // methode constante = ne peut rien modifier dans l'objet

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET
			  << ";amount:" << BLUE << _amount << RESET
			  << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET
			  << ";amount:" << BLUE << _amount << RESET
			  << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << BLUE << _nbAccounts << RESET
			  << ";total:" << BLUE << _totalAmount << RESET
			  << ";deposits:" << BLUE << _totalNbDeposits << RESET
			  << ";withdrawals:" << BLUE << _totalNbWithdrawals << RESET
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET
			  << ";p_amount:" << BLUE << _amount << RESET
			  << ";deposit:" << BLUE << deposit << RESET;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << BLUE << _amount << RESET
			  << ";nb_deposits:" << BLUE << _nbDeposits << RESET
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET
			  << ";p_amount:" << BLUE << _amount << RESET;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << BLUE << withdrawal << RESET
				  << ";amount:" << BLUE << _amount << RESET
				  << ";nb_withdrawals:" << BLUE << _nbWithdrawals << RESET
				  << std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << RESET
			  << ";amount:" << BLUE << _amount << RESET
			  << ";deposits:" << BLUE << _nbDeposits << RESET
			  << ";withdrawals:" << BLUE << _nbWithdrawals << RESET
			  << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		*ptr = NULL;
	std::time_t	now = std::time(ptr); // nb secondes depuis 1/1/1970
	std::tm*	localTime = std::localtime(&now); // conversion en annee, mois, jour, h, min, s

	std::cout << "["
			  << (localTime -> tm_year + 1900)
			  << (localTime -> tm_mon + 1 < 10 ? "0" : "") << (localTime -> tm_mon + 1)
			  << (localTime -> tm_mday < 10 ? "0" : "") << (localTime -> tm_mday)
			  << "_"
			  << (localTime -> tm_hour)
			  << (localTime -> tm_min)
			  << (localTime -> tm_sec)
			  << "]";

}
