#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    string thought;
    cout<<"Enter your thought for today:\n";
    getline(cin, thought);
    ofstream outFile("journal.txt", ios::app);
    if(!outFile)
    {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    outFile<<thought<<endl;
    outFile.close();
    cout<<"Your thought has been recorded in journal.txt"<<endl;
    ifstream inFile("journal.txt");
    if(!inFile)
    {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    int count = 0;
    string line;
    while(getline(inFile, line))
    {
        if(!line.empty())
        {
            count++;
        }
    }
    cout<<"Total number of entries in your journal: "<<count<<endl;
    inFile.close();
    return 0;
}