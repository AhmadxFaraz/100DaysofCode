#include<iostream>
#include<string>
using namespace std;
template <typename T1, typename T2>
class Pair
{
    public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void display()
    {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};
int main()
{
    Pair<int, double> p1(10, 20.5);
    p1.display();

    Pair<string, int> p2("Age", 25);
    p2.display();

    return 0;
}