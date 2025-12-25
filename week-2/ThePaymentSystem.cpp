#include<iostream>
using namespace std;
class IPayable
{
    public:
    virtual void pay() const = 0;
    virtual ~IPayable() {}
};
class Invoice : public IPayable
{
    private:
    double amount;
    public:
    Invoice(double amt) : amount(amt) {}
    void pay() const override
    {
        cout << "Paying invoice of amount: $" << amount << endl;
    }
};
class EmployeeSalary : public IPayable
{
    private:
    double salary;
    public:
    EmployeeSalary(double sal) : salary(sal) {}
    void pay() const override
    {
        cout << "Paying employee salary of amount: $" << salary << endl;
    }
};
int main()
{
    IPayable* payables[3];
    payables[0] = new Invoice(1500);
    payables[1] = new EmployeeSalary(3000);
    payables[2] = new Invoice(2500);
    for(int i = 0; i < 3; i++)
    {
        payables[i]->pay();
    }
    for(int i = 0; i < 3; i++)
    {
        delete payables[i];
    }
    return 0;
}