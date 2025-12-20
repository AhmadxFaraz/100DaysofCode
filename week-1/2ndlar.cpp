#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int main()
{
    int arr[10];
    cout<<"Enter 10 numbers"<<endl;
    for(int i = 0; i<10; i++)
    cin>>arr[i];
    int i1 = 0;
    int i2 = 0;
    int max = 0;
    int max1;
    for(int i = 0; i<9; i++)
    {
        if(arr[i]>=max)
        {
            i1=i;
            max = arr[i];
        }
        else
        max = max;
    }
    int b[9];
    for(int i = 0; i<i1; i++)
    {
        b[i]=arr[i];
    }
    for(int i = i1; i<9; i++)
    {
        b[i]=arr[i+1];
    }
    for(int i = 0; i<9; i++)
    {
        if(b[i]>=max1)
        {
            i2=i;
            max1 = b[i];
        }
        else
        max1 = max1;
    }
    cout<<"Second larget number is "<<b[i2]<<endl;
}