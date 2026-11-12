#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name);

    string getAccountType() const override;

    double calculateInterest() const override;
};

#endif