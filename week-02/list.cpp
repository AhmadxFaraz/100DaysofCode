#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    set<string> guestlist;
    string name;
    for(int i = 0; i < 5; i++)
    {
        cout<<"Guest "<<i+1<<": ";
        getline(cin, name);
        guestlist.insert(name);
    }
    cout<<"\nFinal Guest List: "<<endl;
    for(const string& guest : guestlist)
    {
        cout<<guest<<endl;
    }
    return 0;
}