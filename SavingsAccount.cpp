#include "SavingsAccount.h"

// Constructor
SavingsAccount::SavingsAccount(int accNo, string name)
    : Account(accNo, name)
{
    interestRate = 4.0;
}

// Account type
string SavingsAccount::getAccountType() const
{
    return "Savings Account";
}

// Calculate interest
double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate / 100;
}