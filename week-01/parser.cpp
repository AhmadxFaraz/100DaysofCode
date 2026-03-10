#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
int main()
{
    cout<<"Enter a Sentence."<<endl;
    string L;
    getline(cin,L);
    int x = L.length();
    int vow=0;
    int cons=0;
    int num=0;
    int space=0;
    int punct=0;
    for(int i = 0; i<x; i++)
    {
        L[i]=tolower(L[i]);
        if(isalpha(L[i]))
        {
            if(L[i]=='a' || L[i]=='e' || L[i]=='i' || L[i]=='o' || L[i]=='u')
            vow++;
            else
            cons++;
        }
        else if(isdigit(L[i]))
        num++;
        else if(isblank(L[i]))
        space++;
        else if(ispunct(L[i]))
        punct++;
    }
    cout<<"Total number of vowels = "<<vow<<", consonant = "<<cons;
    cout<<", punctuation & special characters = "<<punct<<", space = ";
    cout<<space<<" & numbers = "<<num<<" in the given sentence."<<endl;
    return 0;
}