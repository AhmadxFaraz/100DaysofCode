#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, string> dictionary;
    int choice;

    do
    {
        cout << "\n--- Digital Dictionary ---\n";
        cout << "1. Add a word\n";
        cout << "2. Search for a word\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            string word, meaning;
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);

            dictionary[word] = meaning;
            cout << "Word added successfully.\n";
        }
        else if (choice == 2)
        {
            string searchWord;
            cout << "Enter word to search: ";
            getline(cin, searchWord);

            if (dictionary.find(searchWord) != dictionary.end())
            {
                cout << "Meaning: " << dictionary[searchWord] << endl;
            }
            else
            {
                cout << "Word not found.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting dictionary.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}