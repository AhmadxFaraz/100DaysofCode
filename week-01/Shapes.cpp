#include<iostream>
using namespace std;
class Shape
{
    protected:
    string color;
    public:
    Shape(const string& c) : color(c) {}
    virtual void draw() const
    {
        cout << "Drawing a shape. " << endl;
    }
};
class Circle : public Shape
{
    public:
    Circle(const string& c) : Shape(c) {}
    void draw() const override
    {
        cout << "Drawing a "<< color << " circle." <<endl;
    }
};
int main()
{
    Shape s("Red");
    s.draw();
    Circle c("Blue");
    c.draw();
    return 0;
}