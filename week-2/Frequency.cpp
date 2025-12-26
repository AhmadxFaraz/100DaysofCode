#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
int main()
{
    map<string, int> wordcount;
    string sentence;
    cout<<"Enter a sentence: ";
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    while(ss>>word)
    {
        wordcount[word]++;
    }
    cout<<"\nWord Frequency:\n";
    for(const auto& pair : wordcount)
    {
        cout<<pair.first<<": "<<pair.second<<endl;
    }
    return 0;
}