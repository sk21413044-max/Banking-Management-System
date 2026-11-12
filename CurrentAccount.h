#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
public:
    CurrentAccount(int accNo, string name);

    string getAccountType() const override;

    double calculateInterest() const override;
};

#endif