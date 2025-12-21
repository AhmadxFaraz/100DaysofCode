#include <iostream>
using namespace std;
int countways(int n);
int main()
{
    cout<<"This program will tell you the number of ways you can climb a stair up, given you can go up by only 1 or 2 steps."<<endl;
    cout<<"Enter the number of stairs..."<<endl;
    int n;
    do
    {
        cin>>n;
        if(n<0)
        {
            cout<<"Invalid input...\nEnter again..."<<endl;
        }
    }while(n<0);
    cout<<"Number of ways you can climb up the stairs are : "<<countways(n)<<"."<<endl;
    return 0;
}
int countways(int n)
{
    if (n == 0) 
    {
        return 1;
    }
    else if (n == 1) 
    {
        return 1;
    }
    else if (n==2)
    {
        return 2;
    }
    return countways(n - 1) + countways(n - 2);
}