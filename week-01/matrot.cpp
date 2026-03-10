#include <iostream>
using namespace std;
void swap(int &a, int &b);
int main()
{
    int A[3][3];
    cout<<"Give a 3*3 matrix and this code will rotate it by 90 degrees."<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<"Enter the ("<<i+1<<","<<j+1<<")th element"<<endl;
            cin>>A[i][j];
        }
    }
    cout<<"Transpose of the given 3*3 matrix is..."<<endl;
    int B[3][3];
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            B[i][j]=A[j][i];
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
    /*for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            swap(A[i][j],A[i][2-j]);
        }
    }*/
   swap(B[0][0],B[0][2]);
   swap(B[1][0],B[1][2]);
   swap(B[2][0],B[2][2]);
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
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
