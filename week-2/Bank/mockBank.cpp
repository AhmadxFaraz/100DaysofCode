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
    Account(string accName, double initialBalance) : name(accName), balance(initialBalance) {}
    string getName() const
    {
        return name;
    }
    double getBalance() const
    {
        return balance;
    }
};
void saveToFile(const Account& a)
{
    ofstream outFile("accounts.txt", ios::app);
    if(!outFile)
    {
        cout<<"Error opening file!"<<endl;
        return;
    }
    outFile<<a.getName()<<" "<<a.getBalance()<<endl;
    outFile.close();
}
int main()
{
    Account account[3] = {Account("Alice", 1500.50), Account("Bob", 2300.75), Account("Charlie", 3200.00)};
    for(int i = 0; i < 3; i++)
    {
        saveToFile(account[i]);
    }
    return 0;
}