#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<map>
using namespace std;
class Account
{
    private:
    int Account_Number;
    double Balance;
    string Name;
    public:
    Account(string n, double b, int a) : Name(n), Balance(b), Account_Number(a) {}
    void display()
    {
        cout<<"Details for your Account\n";
        cout<<Account_Number;
        cout<<Name<<" : "<<Balance<<endl;
    }
    double getBalance()
    {
        return Balance;
    }
};
int main()
{
    string Name;
    double balance;
    int AccN;
    map<string, double> Accounts;
    cout<<"\t–––Welcome to My Bank–––\t"<<endl;
    int choice;
    cout<<"1.Create a Account\n";
    cout<<"2.Check your Balance\n";
    cout<<"3.Deposit Money\n";
    cout<<"4.Withdraw Money\n";
    cout<<"5.View Transaction histroy\n";
    cout<<"6.Quit\n";
}