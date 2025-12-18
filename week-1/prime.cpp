#include <iostream>
using namespace std;
int main()
{
    int start, end;
    cout<<"Enter two numbers, and I'll display the prime numbers in between them"<<endl;
    cout<<"Start number"<<endl;
    cin>>start;
    cout<<"End number"<<endl;
    cin>>end;
    int m = start;
    int n = end;
    int sum = 0;
    for(int i = m; i<=n; i++)
    {
        int count = 0;
        for(int j = 1; j<=i; j++)
        {
            if(i%j==0)
            count++;
        }
        if(count==2)
        cout<<i<<" ";
        if(count==2)
        sum+=i;
    }
    cout<<"The sum is "<<sum<<endl;
    return 0;
}
