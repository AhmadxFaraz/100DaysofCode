#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;
void swap(int &a, int &b);
void swap(string &a, string &b);
void swap(float &a, float &b, float &c);
int main()
{
    cout<<"What do you want to swap?"<<endl;
    cout<<"1.Numbers?\n2.String?\n3.Rotate three Floats?"<<endl;
    int n;
    do{
        cin>>n;
        if(n!=1 && n!=2 && n!=3)
        {
            cout<<"Invalid input...\nEnter again...\nOptions are\n1...\n2...\n3..."<<endl;
        }
    }
    while(n!=1 && n!=2 && n!=3);
    if(n==1)
    {
        int n1,n2;
        cout<<"Enter 1st number - "<<endl;
        cin>>n1;
        cout<<"Enter 2nd number - "<<endl;
        cin>>n2;
        swap(n1,n2);
    }
    else if(n==2)
    {
        string s1,s2;
        cout<<"Enter 1st string - "<<endl;
        cin>>s1;
        cout<<"Enter 2nd strin - "<<endl;
        cin>>s2;
        swap(s1,s2);
    }
    else if(n==3)
    {
        float f1,f2,f3;
        cout<<"Enter 1st float - "<<endl;
        cin>>f1;
        cout<<"Enter 2nd float - "<<endl;
        cin>>f2;
        cout<<"Enter 3rd float - "<<endl;
        cin>>f3;
        swap(f1,f2,f3);
    }
    cout<<endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout<<"1st number = "<<a<<", second number = "<<b;
}
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
    cout<<"1st string = "<<a<<", second string = "<<b;
}
void swap(float &a, float &b, float &c)
{
    float temp1 = a;
    float temp2 = b;
    a = temp2;
    b = c;
    c = temp1;
    cout<<"1st float = "<<a<<", second float = "<<b<<", third float = "<<c;
}