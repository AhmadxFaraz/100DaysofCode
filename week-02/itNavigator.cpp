#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    vector<int> numbers;
    srand(time(0));
    for(int i=0; i<10; i++)
    {
        numbers.push_back(rand()%100);
    }
    cout<<"All numbers:\n";
    for(vector<int>::iterator it = numbers.begin(); it!=numbers.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Even numbers\n";
    for(vector<int>::iterator it = numbers.begin(); it!=numbers.end(); ++it)
    {
        if(*it%2==0)
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}