#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, double> products = {
        {"Laptop", 75000},
        {"Phone", 40000},
        {"Headphones", 3000},
        {"Keyboard", 2500}
    };

    for (auto& item : products)
    {
        item.second *= 0.9;
    }

    cout << "Sale Price List:\n";

    for_each(products.begin(), products.end(),
             [](const pair<string, double>& item) {
                 cout << item.first << ": ₹" << item.second << endl;
             });

    return 0;
}