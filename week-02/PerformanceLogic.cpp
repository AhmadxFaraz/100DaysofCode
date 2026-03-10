#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
int main()
{
    vector<int> v = {10, 20, 30, 40};
    list<int> l = {10, 20, 30, 40};
    v.insert(v.begin(),50);
    l.push_front(50);
    cout<<"Vector contents: ";
    for(int x : v)
    {
        cout<< x <<" ";
    }
    cout<<endl;
    cout<<"List contents: ";
    for(int x : l)
    {
        cout<< x <<" ";
    }
    cout<<endl;
    return 0;
}