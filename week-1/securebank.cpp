#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
    private:
    string AccountHolder;
    double Balance;
    public:
    BankAccount(string name, double initialBalance)
    {
        AccountHolder = name;
        if (initialBalance >= 0)
            Balance = initialBalance;
        else
            Balance = 0;
    }
    void deposit(double amount);
    void withdraw(double amount);
    void display();
};
void BankAccount::deposit(double amount)
{
    if(amount>0)
    Balance += amount;
}
void BankAccount::withdraw(double amount)
{
    if(amount<Balance && amount>0)
    Balance -= amount;
}
void BankAccount::display()
{
    cout<<"Current Balance is : "<<Balance<<endl;
}
int main()
{
    BankAccount B("X", 100);
    B.deposit(100);
    B.withdraw(50);
    B.display();
}
