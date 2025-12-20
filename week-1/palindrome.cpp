#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string L;
    cout<<"This code checks if a word is a Palindrom"<<endl;
    cout<<"Enter a word"<<endl;
    cin>>L;
    int x = L.length();
    int y = x/2;
    int count=0;
    for(int i = 0; i<y; i++)
    {
        if(L[i]==L[x-(i+1)])
        count++;
    }
    bool isPalindrome = true;
    for(int i = 0; i < y; i++) 
    {
        if(L[i] != L[x-(i+1)]) 
        {
            isPalindrome = false;
            break; // Stop immediately!
        }
    }
    if(isPalindrome==true)
    cout<<"This word is a Palindrome"<<endl;
    else
    cout<<"This word is not a Palindrome"<<endl;
}