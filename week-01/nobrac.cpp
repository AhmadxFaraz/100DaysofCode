#include <iostream>
#include <string>
using namespace std;
void swap(int &a, int &b);
int main()
{
    int arr[5] = {1,2,3,4,5};
    int* ptr = arr;
    int sum = 0;
    cout<<"Initial array is \n";
    cout<<"arr[5] = {";
    for(int i = 0; i < 5; i++)
    {
        cout<<" "<<*(ptr+i)<<" ";
    }
    cout<<"}"<<endl;
    for(int i = 0; i < 5; i++)
    {
        sum += *(ptr + i);
    }
    cout<<"The sum of array elements is : "<<sum<<endl;
    int max = 0;
    for(int i = 0; i < 5; i++)
    {
        if(*(ptr+i)>max)
        {
            max=*(ptr+i);
        }
        else
        {
            max = max + 0;
        }
    }
    cout<<"The maximum value element is : "<<max<<endl;
    int x = 2;
    for(int i = 0; i<2; i++)
    {
        swap(*(ptr+i), *(ptr+(4-i)));
    }
    cout<<"Array after reversing is\n";
    cout<<"arr[5] = {";
    for(int i = 0; i < 5; i++)
    {
        cout<<" "<<*(ptr+i)<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}