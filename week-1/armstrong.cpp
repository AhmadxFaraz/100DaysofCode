#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m,n,o,r;
    cout<<"Enter a number"<<endl;
    cin>>n;
    m = n;
    o = n;
    int sum = 0;
    int c = 0;
    while(m>0)
    {
        m=m/10;
        c++;
    }
    while(o>0)
    {
        r=o%10;
        sum += pow(r,c);
        o=o/10;
    }
    if(n==sum)
    cout<<"This number is an armstrong number"<<endl;
    else
    cout<<"This number is not an armstrong number"<<endl;
    return 0;
}