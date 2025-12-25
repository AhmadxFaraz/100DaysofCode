#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Animal
{
    public:
    virtual void sound()
    {
        cout<<"Animal Sound"<<endl;
    }
    virtual ~Animal() {}
};
class Lion: public Animal
{
    public:
    void sound() override
    {
        cout<<"The Lion says: ";
        cout<<"Roar"<<endl;
    }
};
class Elephant: public Animal
{
    public:
    void sound() override
    {
        cout<<"The Elephant says: ";
        cout<<"Trumpet"<<endl;
    }
};
class Monkey: public Animal
{
    public:
    void sound() override
    {
        cout<<"The Monkey says: ";
        cout<<"Chatter"<<endl;
    }
};
class Dog: public Animal
{
    private:
    char* name;
    public:
    Dog(const char* dogName)
    {
        name = new char[strlen(dogName) + 1];
        strcpy(name, dogName);
    }
    void sound() override
    {
        cout<<"The Dog says: ";
        cout<<"Bark"<<endl;
    }
    ~Dog()
    {
        delete[] name;
    }
};
int main()
{
    Animal* zoo[3];
    zoo[0] = new Lion();
    zoo[1] = new Elephant ();
    zoo[2] = new Monkey();
    Animal* pet = new Dog("Buddy");
    pet->sound();
    delete pet;
    pet = nullptr;
    for(int i=0; i<3; i++)
    {
        zoo[i]->sound();
    }
    for(int i=0; i<3; i++)
    {
        delete zoo[i];
        zoo[i] = nullptr;
    }
    return 0;
}