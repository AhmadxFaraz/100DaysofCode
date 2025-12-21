#include <iostream>
using namespace std;
void reverseString(char* str, int length) 
{
    char* start = str;
    char* end = str + length - 1;
    while (start < end) 
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() 
{
    string name; 
    cout<<"Enter a string : ";
    cin>>name;
    int x = name.length();
    char n[x];
    for(int i = 0; i<x; i++)
    {
        n[i]=name[i];
    }
    reverseString(n, x);
    cout << "Reversed: " << n << endl; 
    return 0;
}