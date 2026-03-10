#include<iostream>
using namespace std;
class SmartPhone
{
    private:
    string brand;
    double price;
    public:
    SmartPhone(string b, double p) : brand(b), price(p) {  }
    void displayInfo() const
    {
        cout << "Brand: " << brand << ", Price: " << price << endl;
    }
};
int main()
{
    SmartPhone sp("TechBrand", 999.0);
    sp.displayInfo();
    return 0;
}