#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main()
{
    map<int, vector<string>> gradeStudents;

    gradeStudents[10].push_back("Alice");
    gradeStudents[10].push_back("Bob");
    gradeStudents[12].push_back("Charlie");

    cout << "Grade-wise Student List:\n";
    for (const auto& entry : gradeStudents)
    {
        cout << "Grade " << entry.first << ": ";
        for (const string& student : entry.second)
        {
            cout << student << " ";
        }
        cout << endl;
    }
    
    return 0;
}