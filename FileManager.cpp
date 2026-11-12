#include "FileManager.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Save accounts in binary format
bool saveAccounts(const vector<unique_ptr<Account>>& accounts)
{
    ofstream file("accounts.dat", ios::binary | ios::trunc);

    if (!file)
    {
        cout << "\nUnable to save accounts!";
        return false;
    }

    for (const auto& account : accounts)
    {
        int accNo = account->getAccountNumber();

        string name = account->getName();
        int nameLength = static_cast<int>(name.size());

        char type = (account->getAccountType() == "Savings Account")
                    ? 'S' : 'C';

        double balance = account->getBalance();

        file.write(reinterpret_cast<const char*>(&accNo), sizeof(accNo));

        file.write(reinterpret_cast<const char*>(&nameLength),
                   sizeof(nameLength));

        file.write(name.data(), nameLength);

        file.write(reinterpret_cast<const char*>(&type), sizeof(type));

        file.write(reinterpret_cast<const char*>(&balance),
                   sizeof(balance));
    }

    if (!file)
    {
        cout << "\nError while writing account data!";
        return false;
    }

    return true;
}

// Load accounts from binary file
bool loadAccounts(vector<unique_ptr<Account>>& accounts)
{
    ifstream file("accounts.dat", ios::binary);

    if (!file)
    {
        return false;
    }

    accounts.clear();

    while (true)
    {
        int accNo;
        int nameLength;

        file.read(reinterpret_cast<char*>(&accNo), sizeof(accNo));

        if (!file)
            break;

        file.read(reinterpret_cast<char*>(&nameLength),
                  sizeof(nameLength));

        if (!file || nameLength < 0 || nameLength > 1000)
            break;

        string name(nameLength, '\0');

        file.read(&name[0], nameLength);

        if (!file)
            break;

        char type;
        double balance;

        file.read(reinterpret_cast<char*>(&type), sizeof(type));

        file.read(reinterpret_cast<char*>(&balance), sizeof(balance));

        if (!file || balance < 0)
            break;

        unique_ptr<Account> account;

        if (type == 'S')
        {
            account = make_unique<SavingsAccount>(accNo, name);
        }
        else if (type == 'C')
        {
            account = make_unique<CurrentAccount>(accNo, name);
        }
        else
        {
            break;
        }

        account->setBalance(balance);

        accounts.push_back(move(account));
    }

    return true;
}