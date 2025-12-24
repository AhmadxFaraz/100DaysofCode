#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
    private:
    char* data;
    public:
    MyString(const char* str)
    {
        int len = strlen(str);
        data = new char[len+1];
        strcpy(data, str);
        cout << "Constructor: Memory allocated for \"" << data << "\"\n";
    }
    MyString(const MyString& other) 
    {
        int len = strlen(other.data);
        data = new char[len + 1];
        strcpy(data, other.data);
        cout << "Copy Constructor: Memory allocated for \"" << data << "\"\n";
    }

    MyString& operator=(const MyString& other)
    {
        if (this != &other) 
        {
            delete[] data;
            int len = strlen(other.data);
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        cout << "Copy Assignment: Memory allocated for \"" << data << "\"\n";
        return *this;
    }
    void set(const char* str)
    {
        if(!str) return;
        delete[] data;
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    ~MyString()
    {
        cout<<"Destructor: Memory freed for \""<<data<<"\"\n";
        delete[] data;
        data = nullptr;
    }
    void display() const
    {
        cout<<"String = "<<data<<endl;
    }
};
int main()
{
    MyString str1("Hello, World!");
    str1.display();
    MyString str2 = str1;
    str2.display();
    str2.set("Goodbye, World!");
    str2.display();
    str1.display();
    return 0;
}