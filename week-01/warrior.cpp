#include<iostream>
#include<cstring>
using namespace std;
class Warrior
{
    private:
    const string faction;
    int health;
    public:
    Warrior(string f, int h) : faction(f), health(h) {  }
    string getFaction() const
    {
        return faction; 
    }
    int getHealth() const
    {
        return health;
    }
};
int main()
{
    Warrior w("Knights", 100);
    cout << "Faction: " << w.getFaction() << endl;
    cout << "Health: " << w.getHealth() << endl;
    return 0;
}