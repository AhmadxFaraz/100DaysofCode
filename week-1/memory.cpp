#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 1;
    char h = 'a';
    double d = 400;
    int* p1 = &n;
    char* p2 = &h;
    double* p3 = &d;
    cout<<p1<<endl;
    cout<<static_cast<void*>(p2)<<endl;
    cout<<p3<<endl;
    p1++;
    p2++;
    p3++;
    cout<<p1<<endl;;
    cout<<static_cast<void*>(p2)<<endl;
    cout<<p3<<endl;
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;
    return 0;
}