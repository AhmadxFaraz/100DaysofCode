#include<iostream>
#include<string>
using namespace std;
class Rectangle
{
    private:
    int length;
    int breadth;
    public:
    Rectangle(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    int calcArea() const;
    void calcPeri() const;
    bool compArea(const Rectangle& r) const;
};
int Rectangle::calcArea() const
{
    cout<<"Area = "<<length*breadth<<endl;
    return length*breadth;
}
void Rectangle::calcPeri() const
{
    cout<<"Perimeter = "<<2*(length+breadth)<<endl;
}
bool Rectangle::compArea(const Rectangle& r) const
{
    return this->calcArea() > r.calcArea();
}
int main()
{
    Rectangle r1(2,3), r2(3,4);
    r1.calcArea();
    r1.calcPeri();
    r2.calcArea();
    r2.calcPeri();
    if(r1.compArea(r2))
    {
        cout<<"Area of r1 is greater than area of r2"<<endl;
    }
    else
    {
        cout<<"Area of r1 is less than r2"<<endl;
    }
    return 0;
}