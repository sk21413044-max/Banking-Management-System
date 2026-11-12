#include "CurrentAccount.h"

// Constructor
CurrentAccount::CurrentAccount(int accNo, string name)
    : Account(accNo, name)
{
}

// Account type
string CurrentAccount::getAccountType() const
{
    return "Current Account";
}

// No interest for current account
double CurrentAccount::calculateInterest() const
{
    return 0.0;
}