#include<iostream>
#include<string>
using namespace std;
struct student
{
    string name;
    int roll;
    int marks[3];
};
void printStudentDetails(const student& s) {
    int sum = 0;
    for (int i = 0; i < 3; i++) 
    {

        sum += s.marks[i];
    }
    float avg = sum / 3.0;
    cout << "Roll No: " << s.roll << endl;
    cout << "Name   : " << s.name << endl;
    cout << "Average Marks: " << avg << endl;
    cout << "------------------------\n";
}
int main()
{
   student* students = new student[3];
   for (int i = 0; i < 3; i++) 
   {
        cout << "Enter details for Student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> students[i].roll;
        cout << "Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,students[i].name);
        cout << "Enter 3 marks:\n";
        for (int j = 0; j < 3; j++) 
        {
            cout<<"Marks in subject "<<(j+1)<<" is = ";
            cin >> students[i].marks[j];
        }
   }
   cout<<endl;
   cout << "------------------------\n";
   for (int i = 0; i < 3; i++) 
   {
        printStudentDetails(students[i]);
   }
   delete[] students;
   students = nullptr;
   return 0;
}