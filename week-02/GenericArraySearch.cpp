#include<iostream>
#include<string>
using namespace std;
template <typename T>
int findIndex(T arr[], int size, T target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1; // Target not found
}
int main()
{
    int intArr[] = {10, 20, 30, 40, 50};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    string stringArr[] = {"apple", "banana", "cherry", "date", "elderberry"};

    int intTarget = 30;
    double doubleTarget = 4.4;
    string stringTarget = "cherry";

    cout << "Index of " << intTarget << " in intArr: " << findIndex(intArr, 5, intTarget) << endl;
    cout << "Index of " << doubleTarget << " in doubleArr: " << findIndex(doubleArr, 5, doubleTarget) << endl;
    cout << "Index of \"" << stringTarget << "\" in stringArr: " << findIndex(stringArr, 5, stringTarget) << endl;

    return 0;
}