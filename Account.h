#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    int accountNumber;
    string name;
    double balance;

public:
    void setBalance(double amount);
    // Constructor
    Account(int accNo, string customerName);
    void setName(string newName);
    // Banking operations
    void deposit(double amount);
    bool withdraw(double amount);

    // Getter functions
    int getAccountNumber() const;
    string getName() const;
    double getBalance() const;

    // Pure virtual functions
    virtual string getAccountType() const = 0;
    virtual double calculateInterest() const = 0;

    // Display function
    void display() const;

    // Virtual destructor
    virtual ~Account() = default;
};

#endif