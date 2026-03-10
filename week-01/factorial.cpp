#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int factorial(int n) 
{
    if (n <= 1) {
        cout << "Base case reached! Factorial(1) = 1" << endl;
        return 1;
    } else {
        cout << "Level " << n << ": Calling factorial(" << n - 1 << ")..." << endl;
        int resultFromBelow = factorial(n - 1); 
        int finalResult = n * resultFromBelow;
        cout << "Level " << n << ": Received " << resultFromBelow << " from below. Returning " << finalResult << endl;
        return finalResult;
    }
}
int main()
{
    int n;
    cout<<"This code calculates the factorial of a number"<<endl;
    cout<<"Tell me the number you want to know factorial of"<<endl;
    cin>>n;
    int x = factorial(n);
    cout<<"Umm... here have it"<<endl;
    cout<<"Factorial of the number "<<n<<" is "<<x<<"."<<endl;
    return 0;
}