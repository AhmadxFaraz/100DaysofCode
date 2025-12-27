#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> numbers = {50, -10, 120, 300, -45, 90, 150, -3, 200};

    int count = count_if(numbers.begin(), numbers.end(),
                          [](int x) {
                              return x > 100;
                          });

    cout << "Numbers greater than 100: " << count << endl;

    numbers.erase(
        remove_if(numbers.begin(), numbers.end(),
                  [](int x) {
                      return x < 0;
                  }),
        numbers.end()
    );

    sort(numbers.begin(), numbers.end());

    cout << "Vector after removing negatives:\n";
    for (int n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}