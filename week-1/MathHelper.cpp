#include<iostream>
using namespace std;
class MathHelper
{
    public:
    static int square(int x)
    {
        return x * x;
    }
    static int cube(int x)
    {
        return x * x * x;
    }
};
int main()
{
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    cout << "Square of "<<x<<": " << MathHelper::square(x) << endl;
    cout << "Cube of "<<x<<": " << MathHelper::cube(x) << endl;
    return 0;
}