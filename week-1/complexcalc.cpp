#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i) {}
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (imag == other.imag);
    }

    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main()
{
    cout<<"Enter real and imaginary parts of 1st complex number:\n";
    int r1, i1;
    cin>>r1>>i1;
    cout<<"Enter real and imaginary parts of 2nd complex number:\n";
    int r2, i2;
    cin>>r2>>i2;
    Complex c1(r1, i1);
    c1.display();
    Complex c2(r2, i2);
    c2.display();
    Complex c3 = c1 + c2;
    cout<<"Sum: ";
    c3.display();
    cout<<"Verifying addition...\n";
    if (c3 == Complex(r1 + r2, i1 + i2))
    {
        cout << "Correct addition\n";
    }
    else
    {
        cout << "Incorrect addition\n";
    }
    return 0;
}