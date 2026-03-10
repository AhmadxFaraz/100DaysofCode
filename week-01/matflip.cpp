#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int A[3][3];
    cout<<"Give a 3*3 matrix and this code will give you its transpose."<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<"Enter the ("<<i+1<<","<<j+1<<")th element"<<endl;
            cin>>A[i][j];
        }
    }
    int B[3][3];
    cout<<"Transpose of the given 3*3 matrix is..."<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            B[i][j] = A[j][i];
        }
    }
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}