#include "FileManager.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <utility>

using namespace std;
int main()
{
    int choice;
    vector<unique_ptr<Account>> accounts;
    loadAccounts(accounts);
    cout << "\nPrevious accounts loaded successfully!\n";

    do
    {
        cout << "\n====================================\n";
        cout << "       BANKING MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Create Account\n";
        cout << "2. Display Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Search Account\n";
        cout << "6. Modify Account\n";
        cout << "7. Delete Account\n";
        cout << "8. Display All Accounts\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
{
    int accNo, type;
    string customerName;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    bool exists = false;

for (const auto& acc : accounts)
{
    if (acc->getAccountNumber() == accNo)
    {
        exists = true;
        break;
    }
}

if (exists)
{
    cout << "\nAccount number already exists!";
    break;
}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "\nSelect Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Current Account\n";
    cout << "Enter choice: ";
    cin >> type;

    unique_ptr<Account> account;

    if (type == 1)
    {
        account = make_unique<SavingsAccount>(
            accNo, customerName);
    }
    else if (type == 2)
    {
        account = make_unique<CurrentAccount>(
            accNo, customerName);
    }
    else
    {
        cout << "\nInvalid Account Type!\n";
        break;
    }

    cout << "Enter Initial Deposit: ";
    cin >> amount;

    account->deposit(amount);

    accounts.push_back(move(account));

saveAccounts(accounts);

accounts.back()->display();

    break;
}
             case 2:
{
    int accNo;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    bool found = false;

    for (const auto& account : accounts)
    {
        if (account->getAccountNumber() == accNo)
        {
            account->display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nAccount not found!";

    break;
}

            case 3:
{
    int accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;


    for (const auto& account : accounts)
    {
        if (account->getAccountNumber() == accNo)
        {
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            if (amount <= 0)
{
    cout << "\nInvalid deposit amount!";
    break;
}

            account->deposit(amount);
            saveAccounts(accounts);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nAccount not found!";

    break;
}

            case 4:
{
    int accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (const auto& account : accounts)
    {
        if (account->getAccountNumber() == accNo)
        {
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            if (amount <= 0)
{
    cout << "\nInvalid withdrawal amount!";
    break;
}

            account->withdraw(amount);
            saveAccounts(accounts);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nAccount not found!";

    break;
}

            case 5:
{
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number to Search: ";
    cin >> accNo;

    for (const auto& account : accounts)
    {
        if (account->getAccountNumber() == accNo)
        {
            cout << "\nAccount Found!";
            account->display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!";
    }

    break;
};

            case 6:
{
    int accNo;
    string newName;
    bool found = false;

    cout << "\nEnter Account Number to Modify: ";
    cin >> accNo;

    for (const auto& account : accounts)
    {
        if (account->getAccountNumber() == accNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Customer Name: ";
            getline(cin, newName);

            account->setName(newName);
            saveAccounts(accounts);

            cout << "\nAccount Updated Successfully!";
            account->display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!";
    }

    break;
}

            case 7:
{
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number to Delete: ";
    cin >> accNo;

    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if ((*it)->getAccountNumber() == accNo)
        {
            accounts.erase(it);
            saveAccounts(accounts);

            cout << "\nAccount Deleted Successfully!";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!";
    }

    break;
}
            case 8:
{
    if (accounts.empty())
    {
        cout << "\nNo Accounts Available!";
    }
    else
    {
        cout << "\n===== ALL BANK ACCOUNTS =====\n";

        for (const auto& account : accounts)
        {
            account->display();
        }
    }

    break;
}

            case 9:
                cout << "Thank You for Using Our Banking System!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}