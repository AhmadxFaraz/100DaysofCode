#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Account
{
    private:
    string name;
    double balance;
    public:
    Account(string n, double b) : name(n), balance(b) 
    {
        cout<<"Account created for "<<name<<"."<<endl;
    }
    void display() const
    {
        cout<<"Name: "<<name<<", Balance: "<<balance<<endl;
    }
    ~Account()
    {
        cout<<"Accoutn destroyed for "<<name<<"."<<endl;
    }
};
int main()
{
    vector<Account> accounts;
    accounts.push_back(Account("Alice", 10000));
    accounts.push_back(Account("Bob", 15000));
    accounts.push_back(Account("Cindy", 20000));
    cout<<"Accounts in vector"<<endl;
    for(const auto& acc : accounts)
    {
        acc.display();
    }
    cout<<"Cleaning the vector"<<endl;
    accounts.clear();
    if(accounts.empty())
    {
        cout<<"Vector is empty."<<endl;
    }
    else
    {
        cout<<"Vector is NOT empty."<<endl;
    }
    return 0;
}