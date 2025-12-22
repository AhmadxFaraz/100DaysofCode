#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
    cout<<"Enter number of rows : ";
    cin>>rows;
    cout<<"Enter number of columns : ";
    cin>> cols;
    int** matrix = new int*[rows];
    for(int i = 0; i<rows; i++)
    {
        matrix[i] = new int[cols];
        for(int j = 0; j<cols; j++)
        {
            cout << "Enter (" << i+1 << "," << j+1 << ")th element: ";
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i<rows; i++)
    {
        cout<<"|";
        for(int j = 0; j<cols; j++)
        {
            cout<<"\t"<<matrix[i][j]<<"\t";
        }
        cout<<"|"<<endl;
    }
    for(int i = 0; i<rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}