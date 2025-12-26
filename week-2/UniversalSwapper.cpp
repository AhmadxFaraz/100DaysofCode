#include<iostream>
#include<string>
using namespace std;
template <typename T>
void universalSwap(T &a, T &b) 
{
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x = 10, y = 20;
    cout << "Before swap (int): x = " << x << ", y = " << y << endl;
    universalSwap<int>(x, y);
    cout << "After swap (int): x = " << x << ", y = " << y << endl;

    double p = 5.5, q = 9.9;
    cout << "Before swap (double): p = " << p << ", q = " << q << endl;
    universalSwap<double>(p, q);
    cout << "After swap (double): p = " << p << ", q = " << q << endl;

    string str1 = "Hello", str2 = "World";
    cout << "Before swap (string): str1 = " << str1 << ", str2 = " << str2 << endl;
    universalSwap<string>(str1, str2);
    cout << "After swap (string): str1 = " << str1 << ", str2 = " << str2 << endl;
    
    return 0;
}