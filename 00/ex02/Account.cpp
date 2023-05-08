#include "Account.hpp"
#include <iostream>
#include <ctime>

// Static member variable definitions
int Account::_nbAccounts = 0;         // Initialize number of accounts to 0
int Account::_totalAmount = 0;        // Initialize total amount to 0
int Account::_totalNbDeposits = 0;    // Initialize total number of deposits to 0
int Account::_totalNbWithdrawals = 0; // Initialize total number of withdrawals to 0

// Constructor implementation
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), // Set account index to current number of accounts
      _amount(initial_deposit),   // Set initial amount of account to provided initial deposit
      _nbDeposits(0),             // Initialize number of deposits to 0
      _nbWithdrawals(0)
{                                    // Initialize number of withdrawals to 0
    _nbAccounts++;                   // Increment number of accounts
    _totalAmount += initial_deposit; // Add initial deposit to total amount
    _displayTimestamp();             // Display current timestamp
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl; // Print account creation message
}

// Destructor implementation
Account::~Account(void)
{
    _nbAccounts--;                         // Decrement number of accounts
    _totalAmount -= _amount;               // Subtract current account balance from total amount
    _totalNbDeposits -= _nbDeposits;       // Subtract current account's deposits from total deposits
    _totalNbWithdrawals -= _nbWithdrawals; // Subtract current account's withdrawals from total withdrawals
    _displayTimestamp();                   // Display current timestamp for logging purposes
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";closed" << std::endl; // Print account closing message
}

// Deposit implementation
void Account::makeDeposit(int deposit)
{
    _displayTimestamp(); // Display current timestamp
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"
              << deposit << ";amount:" << _amount + deposit << ";nb_deposits:"
              << _nbDeposits + 1 << std::endl; // Print deposit message
    _amount += deposit;                        // Add deposit amount to account balance
    _nbDeposits++;                             // Increment number of deposits for account
    _totalAmount += deposit;                   // Add deposit amount to total amount
    _totalNbDeposits++;                        // Increment total number of deposits
}

// Withdrawal implementation
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp(); // Display current timestamp
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:"
              << withdrawal;
    if (withdrawal > _amount)
    {                                         // If withdrawal amount is greater than account balance
        std::cout << ";refused" << std::endl; // Print refusal message and return false
        return false;
    }
    std::cout << ";amount:" << _amount - withdrawal << ";nb_withdrawals:"
              << _nbWithdrawals + 1 << std::endl; // Print withdrawal message
    _amount -= withdrawal;                        // Subtract withdrawal amount from account balance
    _nbWithdrawals++;                             // Increment number of withdrawals for account
    _totalAmount -= withdrawal;                   // Subtract withdrawal amount from total amount
    _totalNbWithdrawals++;
    return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(nullptr);
    struct tm *timeinfo = localtime(&now);
    char buffer[20];
    strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}
