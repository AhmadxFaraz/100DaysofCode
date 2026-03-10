#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;
string toBinary(int n);
int toDecimal(string L);
int main() 
{
    cout<<"Enter a number - ";
    int num;
    cin>>num;
    string bin = toBinary(num);
    cout << "Binary: " << bin << endl;
    cout << "Back to Decimal: " << toDecimal(bin) << endl;
    return 0;
}

string toBinary(int n)
{
    int m = n;
    int z = 0;
    int temp = n;
    while (temp > 0)
    {
        temp /= 2;
        z++;
    }
    int s[z];
    int i = 0;
    while (m > 0)
    {
        s[i] = m % 2;
        m /= 2;
        i++;
    }
    string b(z, ' ');
    for (int j = 0; j < z; j++)
    {
        b[j] = s[z - j - 1] + '0';
    }
    return b;
}

int toDecimal(string L)
{
    int N = 0;
    for (char c : L)
    {
        N = N * 2 + (c - '0');
    }
    return N;
}