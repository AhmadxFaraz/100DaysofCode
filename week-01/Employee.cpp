#include<iostream>
#include<string>
using namespace std;
class Employee
{
    protected:
    string name;
    double salary;
    public:
    Employee(string n, double s) : name(n), salary(s) {}
    void displaydetails() const;
};
void Employee::displaydetails() const
{
    cout << "Name: " << name << ", Salary: " << salary << endl;
}
class Manager : public Employee
{
    private:
    double bonus;
    public:
    Manager(string n, double s, double b) : Employee(n, s), bonus(b) {}
    void displaydetails()
    {
        Employee::displaydetails();
        cout << "Bonus: " << bonus << endl;
    }
};
int main()
{
    Employee emp("John Doe", 50000);
    Manager mgr("Jane Smith", 80000, 15000);
    emp.displaydetails();
    mgr.displaydetails();
    return 0;
}