#include<iostream>
#include<string>
using namespace std;
template <typename T>
void printInfo(T val)
{
    cout<<"Generic Value: "<<val<<endl;
}
template <>
void printInfo<bool>(bool val)
{
    cout << "Boolean Value: " << (val ? "True" : "False") << endl;
}
int main()
{
    printInfo(42);
    printInfo(3.14);
    printInfo("Hello, World!");
    printInfo(true);
    printInfo(false);
    return 0;
}