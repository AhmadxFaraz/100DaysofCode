#include<iostream>
#include<string>
using namespace std;
class Employee
{
    public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
};
class FullTimeEmployee : public Employee
{
    private:
    double monthlySalary;
    public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override
    {
        return monthlySalary;
    }
};
class Contractor : public Employee
{
    private:
    double hourlyRate;
    int hoursWorked;
    public:
    Contractor(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }
};
int main()
{
    Employee* employees[5];
    employees[0] = new FullTimeEmployee(3000);
    employees[1] = new Contractor(50, 160);
    employees[2] = new FullTimeEmployee(4500);
    employees[3] = new Contractor(60, 120);
    employees[4] = new FullTimeEmployee(5000);
    for(int i = 0; i < 5; i++)
    {
        cout << "Employee " << i + 1 << " Salary: $" << employees[i]->calculateSalary() << endl;
    }
    double totalPayroll = 0;
    for(int i = 0; i < 5; i++)
    {
        totalPayroll += employees[i]->calculateSalary();
    }
    cout << "Total Monthly Payroll: $" << totalPayroll << endl;
    for(int i = 0; i < 5; i++)
    {
        delete employees[i];
        employees[i] = nullptr;
    }
    return 0;
}