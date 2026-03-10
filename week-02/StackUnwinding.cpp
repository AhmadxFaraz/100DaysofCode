#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
void C()
{
    cout<<"Function C is executing."<<endl;
    cout<<"An error is about to be thrown from C."<<endl;
    throw runtime_error("An error occurred in function C");
    cout<<"This line will not be executed."<<endl;
}
void B()
{
    cout<<"Function B is executing."<<endl;
    C();
    cout<<"This line will not be executed."<<endl;
}
void A()
{
    cout<<"Function A is executing."<<endl;
    try
    {
        B();
    }
    catch (const exception& e)
    {
        cout << "Caught exception in A: " << e.what() << endl;
    }
    cout<<"Function A continues executing after handling the exception."<<endl;
}
int main()
{
    cout<<"Program started."<<endl;
    A();
    cout<<"Program ended."<<endl;
    return 0;
}