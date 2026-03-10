#include <iostream>
#include <cstring>
using namespace std;

class Book 
{
private:
    string title;
    string author;
    double price;

public:
    // Default constructor
    Book() : title("Unknown"), author("Unknown"), price(0.0) {}

    // Parameterized constructor
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    // Discount constructor
    Book(string t, string a) : title(t), author(a), price(10.0) {}

    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Book* books = new Book[3];

    for (int i = 0; i < 3; i++) 
    {
        string title, author;
        double price;

        cout << "\nEnter title: ";
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // clear newline

        books[i] = Book(title, author, price);
    }

    cout << "\nBook Details:\n";
    for (int i = 0; i < 3; i++) {
        books[i].displayDetails();
        cout << endl;
    }

    delete[] books;
    return 0;
}
