#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void safeOpen(const string& filename)
{
    ifstream inFile(filename);
    if(!inFile)
    {
        cout<<"File "<<filename<<" not found. Creating a new blank file... "<<endl;
        ofstream newfile(filename);
        cout<<"Done."<<endl;
        newfile.close();
    }
    else
    {
        cout<<"File "<<filename<<" opened successfully."<<endl;
        inFile.close();
    }
}
int main()
{
    safeOpen("data.txt");
    return 0;
}