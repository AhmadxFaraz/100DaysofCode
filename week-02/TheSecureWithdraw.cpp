#include<iostream>
#include<string>
#include<stdexcept>
#include<exception>
using namespace std;
class InsufficientFundsException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Transaction failed: Insufficient funds.";
    }
};
class Account
{
    private:
    double balance;
    public:
    Account(double initialBalance) : balance(initialBalance) {}
    void withdraw(double amount)
    {
        if(amount > balance)
        {
            throw InsufficientFundsException();
        }
        if(amount <= 0)
        {
            throw invalid_argument("Invalid withdrawal amount.");
        }
        balance -= amount;
        cout<<"Withdrawal successful! Remaining balance: "<<balance<<endl;
    }
};
int main()
{
    Account acc(1000);
    try
    {
        acc.withdraw(1500);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << e.what() << endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}