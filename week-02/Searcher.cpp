#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Account
{
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    int getAccountNumber() const
    {
        return accountNumber;
    }

    string getHolderName() const
    {
        return holderName;
    }
};

int main()
{
    vector<Account> accounts;

    // Add some accounts
    accounts.push_back(Account(101, "Alice", 1000));
    accounts.push_back(Account(102, "Bob", 2000));
    accounts.push_back(Account(103, "Charlie", 3000));

    int searchAccount;
    cout << "Enter account number to search: ";
    cin >> searchAccount;

    // Use find_if with lambda
    auto it = find_if(accounts.begin(), accounts.end(), [searchAccount](const Account& acc) {return acc.getAccountNumber() == searchAccount;});

    if (it != accounts.end())
    {
        cout << "Account found. Holder name: "
             << it->getHolderName() << endl;
    }
    else
    {
        cout << "Account not found." << endl;
    }

    return 0;
}