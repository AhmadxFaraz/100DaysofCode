#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector <string> ShoppingList;
    int choice;
    do
    {
        cout<<"--Shopping List Menu--"<<endl;
        cout<<"1. Add item"<<endl;
        cout<<"2. Remove last item"<<endl;
        cout<<"3. View shopping list"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1)
        {
            string item;
            cout<<"Enter an item name: ";
            cin>>item;
            ShoppingList.push_back(item);
            cout<<"Item added.\nCurrent size: "<<ShoppingList.size()<<endl;
        }
        else if( choice == 2)
        {
            if(!ShoppingList.empty())
            {
                ShoppingList.pop_back();
                cout<<"Last item removed.\nCurrent size: "<<ShoppingList.size()<<endl;
            }
            else{
                cout<<"Shopping List is already empty"<<endl;
            }
        }
        else if(choice == 3)
        {
            cout<<"\nShopping List ("<<ShoppingList.size()<<" items)\n";
            for(int i = 0; i < ShoppingList.size(); i++)
            {
                cout<<i+1<<". "<<ShoppingList[i]<<endl;
            }
        }
        else if(choice == 4)
        {
            cout<<"Exiting Program."<<endl;
        }
        else
        {
            cout<<"Invalid choice... Please try again"<<endl;
        }
    }while(choice!=4);
    return 0;
}