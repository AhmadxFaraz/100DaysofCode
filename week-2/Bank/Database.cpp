#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Account
{
    private:
    string name;
    double balance;
    public:
    Account(string n, double b) : name(n), balance(b) {}
    void display() const
    {
        cout<<"Account Holder: "<<name<<", Balance: $"<<balance<<endl;
    }
};
int main()
{
    string name;
    double balance;
    ifstream inFile("accounts.txt");
    if(!inFile)
    {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    const int max = 10;
    Account* accounts[max];
    int count = 0;
    while(inFile >> name >> balance && count < max)
    {
        accounts[count] = new Account(name, balance);
        count++;
    }
    inFile.close();
    cout<<"Loaded Accounts:\n";
    for(int i = 0; i < count; i++)
    {
        accounts[i]->display();
        delete accounts[i];
        accounts[i] = nullptr;
    }
    return 0;
}