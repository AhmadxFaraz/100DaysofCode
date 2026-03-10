#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int A[3][3];
    cout<<"Give a 3*3 matrix and this code will give you sum of its boundary elements"<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<"Enter the ("<<i+1<<","<<j+1<<")th element"<<endl;
            cin>>A[i][j];
        }
    }
    int bsum = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(i==0 || i==2)
            bsum+=A[i][j];
            else if(j==0 || j==2)
            bsum+=A[i][j];
        }
    }
    cout<<"The sum of boundary elemetns is "<<bsum<<"."<<endl;
    return 0;
}