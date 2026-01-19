#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
#include<map>
#include<ctime>
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
        cout<<Name<<" : "<<Balance<<endl;
        cout<<"Remeber your Accoun Number : "<<Account_Number<<", for future reference/logging"<<endl;
    }
    int getAN()
    {
        return Account_Number;
    }
    string getName()
    {
        return Name;
    }
    double getBalance()
    {
        return Balance;
    }
    void withdraw(double w)
    {
        if(w<=Balance && w>0)
        {
            Balance -= w;
        }
        else if(w<0)
        {
            cout<<"Invalid amount.\n";
        }
        else
        {
            cout<<"Not enough Balance."<<endl;
        }
    }
    void deposit(double d)
    {
        if(d>0)
        {
            Balance += d;
        }
        else if(d<0)
        {
            cout<<"Invalid amount.\n";
        }
    }
};
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

    return string(buffer);
}
Account* findAccountByNumber(vector<Account>& accounts, int accNo)
{
    for (auto &acc : accounts)
    {
        if (acc.getAN() == accNo)
        {
            return &acc;
        }
    }
    return nullptr;
}
int main()
{
    string Name;
    double balance;
    int AccN;
    vector<Account> accounts;
    int choice;
    int acn;
    cout<<"\t---Welcome to My Bank\t---"<<endl;
    ifstream importFile("customer-data.txt");
    if(!importFile)
    {
        ofstream newFile("customer-data.txt");
        newFile.close();
        acn=1;
    }
    else if(importFile)
    {
        while(importFile>>AccN>>Name>>balance)
        {
            accounts.push_back(Account(Name, balance, AccN));
            acn = AccN+1;
        }
        importFile.close();
    }
    do
    {
        cout<<endl;
        cout<<"\t-----------------------------------------\t"<<endl;
        cout<<"\t---What brings you here?---\t"<<endl;
        cout<<"\t1.Create a Account\t\n";
        cout<<"\t2.Check your Balance\t\n";
        cout<<"\t3.Deposit Money\t\n";
        cout<<"\t4.Withdraw Money\t\n";
        cout<<"\t5.View Transaction histroy\t\n";
        cout<<"\t6.Quit\t\n";
        cout<<"\t-----------------------------------------\t";
        cout<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            string name;
            double balance;
            cout<<"Enter your name(one word) : ";
            cin>>name;
            cout<<"Enter amount you want to deposit : ";
            cin>>balance;
            accounts.push_back(Account(name, balance, acn));
            cout<<"Account created successfully!"<<endl;
            Account* acc = findAccountByNumber(accounts, acn);
            acc->display();
            ofstream outFile("customer-data.txt", ios::app);
            outFile<<acc->getAN()<<" "<<acc->getName()<<" "<<acc->getBalance()<<endl;
            outFile.close();
            ofstream txFile("transaction-history.txt", ios::app);
            txFile << acc->getAN() << " "<< "DEPOSIT" << " " << balance << " "<< acc->getBalance() << " "<< getCurrentDateTime()<< endl;
            txFile.close();
            acn++;
        }
        else if(choice==2)
        {
            int searchAcc;
            cout<<"Enter you Account Number : ";
            cin>>searchAcc;
            Account* acc = findAccountByNumber(accounts, searchAcc);
            if(acc!=nullptr)
            {
                cout<<"Hello, "<<acc->getName()<<endl;
                cout<<"Your Current Balance : "<<acc->getBalance()<<endl;
            }
            else
            {
                cout<<"Account not found.\n";
                cout<<"Check your Account nuber... And try again"<<endl;
            }
        }
        else if(choice==3)
        {
            cout<<"Enter you Account Number : ";
            int searchacn;
            cin>>searchacn;
            Account* acc = findAccountByNumber(accounts, searchacn);
            if(acc!=nullptr)
            {
                double amountd;
                cout<<"Hello, "<<acc->getName()<<endl;
                cout<<"Enter amount to DEPOSIT : ";
                cin>>amountd;
                acc->deposit(amountd);
                cout<<"Amount deposited successfully!"<<endl;
                cout<<"Your new balance is "<<acc->getBalance()<<endl;

                ofstream outFile("customer-data.txt");
                for (auto it = accounts.begin(); it != accounts.end(); ++it)
                {
                    outFile<<it->getAN()<<" "<<it->getName()<<" "<<it->getBalance()<<endl;
                }
                outFile.close();
                ofstream txFile("transaction-history.txt", ios::app);
                txFile << acc->getAN() << " "<< "DEPOSIT" << " " << amountd << " "<< acc->getBalance() << " "<< getCurrentDateTime()<< endl;
                txFile.close();
            }
            else
            {
                cout<<"Account not found.\n";
                cout<<"Check your Account number... And try again"<<endl;
            }
        }
        else if(choice==4)
        {
            cout<<"Enter you Account Number : ";
            int accN;
            int search2acn;
            cin>>search2acn;
            Account* acc = findAccountByNumber(accounts, search2acn);
            if(acc!=nullptr)
            {
                cout<<"Hello, "<<acc->getName()<<endl;
                cout<<"Your current balance is : "<<acc->getBalance()<<endl;
                cout<<"Enter amount you want to WITHDRAW : ";
                double amountw;
                cin>>amountw;
                acc->withdraw(amountw);
                cout<<"Your new balance is : "<<acc->getBalance()<<endl;
                ofstream outFile("customer-data.txt");
                for (auto it = accounts.begin(); it != accounts.end(); ++it)
                {
                    outFile<<it->getAN()<<" "<<it->getName()<<" "<<it->getBalance()<<endl;
                }
                outFile.close();
                ofstream txFile("transaction-history.txt", ios::app);
                txFile << acc->getAN() << " "<< "WITHDRAW" << " " << amountw << " "<< acc->getBalance() << " "<< getCurrentDateTime()<< endl;
                txFile.close();
            }
            else
            {
                cout<<"Account not found!"<<endl;
                cout<<"Check your account number... Try again."<<endl;
            } 
        }
        else if(choice==5)
        {
            cout<<"Enter you Account Number : ";
            int search3acn;
            cin>>search3acn;
            Account* acc = findAccountByNumber(accounts, search3acn);
            cout<<"Hello, "<<acc->getName()<<endl;
            if(acc!=nullptr)
            {
                string type;
                double amount;
                double balance;
                string timestamp;
                ifstream txFile("transaction-history.txt");
                while(txFile>>AccN>>type>>amount>>balance)
                {
                    getline(txFile, timestamp);
                    if(AccN==search3acn)
                    {
                        cout<<AccN<<" "<<type<<" "<<amount<<" "<<balance<<" "<<timestamp<<endl;
                    }
                }
                txFile.close();
            }
            else
            {
                cout<<"Account not found..."<<endl;
                cout<<"Check your account number... Try again!"<<endl;
            }
        }
    }while (choice!=6);
    cout<<"Thank you for visiting My Bank"<<endl;
    return 0;
}