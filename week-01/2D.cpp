#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int A[3][3];
    cout<<"Give a 3*3 matrix and then tell a number you want to know if it is there in the matrix."<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<"Enter the ("<<i+1<<","<<j+1<<")th element"<<endl;
            cin>>A[i][j];
        }
    }
    cout<<"What number are you looking for?"<<endl;
    int n;
    cin>>n;
    int b = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if (A[i][j]==n)
            {
                cout<<"I found the number"<<endl;
                cout<<"The number is the ("<<i+1<<","<<j+1<<")th element of the matrix."<<endl;
                b++;
            }
        }
    }
    if(b==0)
        cout<<"404\nNumber not found"<<endl;
    return 0;
}