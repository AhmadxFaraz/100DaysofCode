#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    vector<int> nums;

    srand(time(0));

    for(int i = 0; i < 10; i++)
    {
        nums.push_back(rand() % 100);
    }

    sort(nums.begin(),nums.end(), [](int a, int b){return a > b;});

    for_each(nums.begin(), nums.end(), [](int x){cout<<x<<" ";});

    cout<<endl;
    
    return 0;
}