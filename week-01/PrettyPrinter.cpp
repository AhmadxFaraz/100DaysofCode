#include<iostream>
using namespace std;
class Person
{
    private:
    string name;
    int age;
    public:
    Person(string n, int a) : name(n), age(a) {}
    friend ostream& operator<<(ostream& out, const Person& p);

};
ostream& operator<<(ostream& out, const Person& p)
{
    cout << "Name: " << p.name << ", Age: " << p.age << endl;
    return out;
}
int main()
{
    Person person("Faraz", 18);
    cout << person<<endl;
    return 0;
}