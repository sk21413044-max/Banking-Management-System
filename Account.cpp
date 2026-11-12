#include "Account.h"

// Constructor
Account::Account(int accNo, string customerName)
{
    accountNumber = accNo;
    name = customerName;
    balance = 0.0;
}

// Deposit
void Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "\nAmount deposited successfully!";
    }
    else
    {
        cout << "\nInvalid deposit amount!";
    }
}

// Withdraw
bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid withdrawal amount!";
        return false;
    }

    if (amount > balance)
    {
        cout << "\nInsufficient balance!";
        return false;
    }


    balance -= amount;
    cout << "\nWithdrawal successful!";
    return true;
}
void Account::setName(string newName)
{
    name = newName;
}
void Account::setBalance(double amount)
{
    if (amount >= 0)
    {
        balance = amount;
    }
}
// Getters
int Account::getAccountNumber() const
{
    return accountNumber;
}

string Account::getName() const
{
    return name;
}

double Account::getBalance() const
{
    return balance;
}

// Display
void Account::display() const
{
    cout << "\n========== ACCOUNT DETAILS ==========\n";

    cout << "Account Number : " << accountNumber << endl;
    cout << "Customer Name  : " << name << endl;
    cout << "Account Type   : " << getAccountType() << endl;
    cout << "Balance        : Rs. " << getBalance() << endl;
    cout << "Interest       : Rs. " << calculateInterest() << endl;

    cout << "=====================================\n";
}