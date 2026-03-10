#include<iostream>
#include<string>
using namespace std;
class User
{
    private:
    string name;
    static int userCount;
    public:
    User(string n) : name(n)
    {
        userCount++;
        cout<<"User "<<name<<" created. Total users: "<<userCount<<endl;
    }
    static int getUserCount()
    {
        return userCount;
    }
    ~User()
    {
        userCount--;
        cout<<"User "<<name<<" destroyed. Total users: "<<userCount<<endl;
    }
};
int User::userCount = 0;
int main()
{
    cout<<"Initial User Count: "<<User::getUserCount()<<endl;
    cout<<"Creating users...\n";
    User* users[5];
    for(int i=0; i<5; i++)
    {
        string uname = "User" + to_string(i+1);
        users[i] = new User(uname);
    }
    cout<<"Current User Count: "<<User::getUserCount()<<endl;
    cout<<"Deleting users...\n";
    delete users[2]; // Delete User3
    delete users[4]; // Delete User5
    users[2] = nullptr;
    users[4] = nullptr;
    cout<<"Deleted users 3 and 5.\n";
    cout<<"Final User Count: "<<User::getUserCount()<<endl;
    for(int i=0; i<5; i++)
    {
        if(users[i] != nullptr)
        {
            delete users[i];
            users[i] = nullptr;
        }
    }
    return 0;
}