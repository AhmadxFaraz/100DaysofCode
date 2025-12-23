#include <iostream>
using namespace std;
int add(int a, int b) 
{
    return a + b;
}
int subtract(int a, int b) 
{
    return a - b;
}
int multiply(int a, int b)
{
    return a*b;
}
int compute(int a, int b, int (*operation)(int a, int b))
{
    return operation(a,b);
}
int main()
{
    int a, b;
    cout<<"Enter 1st number : ";
    cin>>a;
    cout<<"Enter 2nd number : ";
    cin>>b;
    cout<<"Sum = "<<compute(a,b, add)<<endl;
    cout<<"Difference = "<<compute(a,b, subtract)<<endl;
    cout<<"Product = "<<compute(a,b, multiply)<<endl;
    return 0;
}