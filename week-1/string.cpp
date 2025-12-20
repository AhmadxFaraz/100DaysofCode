#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int main()
{
    string L; 
    cout<<"Enter a string you want me to compress - ";
    cin>>L;
    int x = L.length();
    int i = 0;
    int k = 0;
    while(i<x)
    {
        if(L[i]==L[i+1])
        {
            i++;
            k++;
        }
        else
        {
            cout<<L[i]<<(k+1);
            i++;
            k = 0;
        }
    }
    cout<<endl;
    return 0;
}