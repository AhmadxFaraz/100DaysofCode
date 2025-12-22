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
    char* charArr = new char[x+1];
    for(int i = 0; i<x; i++)
    {
        charArr[i]=name[i];
    }
    *(charArr +x) = '\0';
    reverseString(charArr, x);
    cout << "Reversed: " << charArr << endl; 
    delete[] charArr;
    return 0;
}