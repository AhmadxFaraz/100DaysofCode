#include<iostream>
using namespace std;
class Account
{
    private:
    double balance;
    friend void audit(const Account& a);
    public:
    Account(double b) : balance(b) {}
};
void audit(const Account& a)
{
    cout<<"Auditing account. Balance = "<<a.balance<<endl;
}
int main()
{
    Account a(5000);
    audit(a);
    return 0;
}