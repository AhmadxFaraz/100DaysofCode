#include <iostream>
using namespace std;
void getCircleStats(float radius, float* area, float* circum);
int main()
{
    float radius = 3;
    float area = 0;
    float circum = 0;
    getCircleStats(radius, &area, &circum);
    cout<<"Area = "<<area<<"\nCircumference = "<<circum<<endl;
    return 0;
}
void getCircleStats(float radius, float* area, float* circum)
{
    *area = (3.14)*radius*radius;
    *circum = 2*(3.14)*radius;
}