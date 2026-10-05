#include <iostream>
#include <string>
#include <limits>
#include <map>
using namespace std;

int getValidInt()
{
    int value;
    while (!(cin >> value))
    {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}

void showMenu()
{
    cout << " ====== Contact Book ====== " << endl;

    cout << " 1. Add Contact \n";
    cout << " 2. Delete Contact \n";
    cout << " 3. Update Contact \n";
    cout << " 4. Search Contact \n";
    cout << " 5. Display Contact \n";
    cout << " 6. Exit \n";
}

int selectChoice()
{
    cout << "Enter your choice (an integer between 1 and 6): ";
    return getValidInt();
}

void addContact(map<string, string> &contacts)
{
    string name, phoneNumber;

    cout << "Enter name of contact: ";
    getline(cin, name);

    cout << "Enter phone number of contact: ";
    getline(cin, phoneNumber);

    if (contacts.find(name) != contacts.end()){
        cout << name << " already exists. Use Update Contact to change the phone number. \n";
        return;
    }

    contacts[name] = phoneNumber;

    cout << "Contact added successfully! \n";
}

void deleteContact(map<string, string> &contacts)
{
    string name;

    if (contacts.empty())
    { // edge case
        cout << "No contact to delete \n";
        return;
    }

    cout << "Which contact you want to delete (please enter exact name): ";
    getline(cin, name);

    if (contacts.find(name) != contacts.end())
    {
        contacts.erase(name);
        cout << "Deleted Successfully! \n";
    }
    else
    {
        cout << "Invalid contact! \n";
    }
}

void updateContact(map<string, string> &contacts)
{ 
    string oldName, oldPhoneNumber, newName, newPhoneNumber;
    bool  updated = false;

    if (contacts.empty()) {
        cout << "No contacts to update.\n";
        return;
    }

    cout << "What do you want to update? \n";

    cout << " 1. Name \n";
    cout << " 2. Phone number \n";
    cout << " 3. Both \n";

    cout << "Select your choice (Enter integer from 1 to 3): ";
    int update = getValidInt();

    switch (update)
    {
    case 1:
        cout << "Enter the name of contact you want to update: ";
        getline(cin, oldName);
        if (contacts.find(oldName) != contacts.end())
        {
            oldPhoneNumber = contacts[oldName];
            cout << "Enter new name: ";
            getline(cin, newName);

            if (contacts.find(newName) == contacts.end())
            {
                contacts.insert({newName, oldPhoneNumber});
                contacts.erase(oldName);
                updated = true;
            } else {
                cout << "Error: New name already exists! \n";
            }

        } else {
            cout << "Contact doesn't exists. \n";
        }

        break;
    case 2:
        cout << "Enter the name of contact you want to update: ";
        getline(cin, oldName);
        if (contacts.find(oldName) != contacts.end())
        {
            cout << "Enter new phone number: ";
            getline(cin, newPhoneNumber);
            contacts[oldName] = newPhoneNumber;
            updated = true;

        }else {
            cout << "Contact doesn't exists. \n";
        }

        break;
    case 3:
        cout << "Enter both the name and phone number of contact you want to update: ";
        cout << "Name: ";
        getline(cin, oldName);
        cout << "Phone number: ";
        getline(cin, oldPhoneNumber);
        if (contacts.find(oldName) != contacts.end())
        {
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new phone number: ";
            getline(cin, newPhoneNumber);
            if (contacts.find(newName) == contacts.end()) {
                contacts.insert({newName, newPhoneNumber});
                contacts.erase(oldName);
                updated = true;
            } else {
                cout << "New name already exists. \n";
            }        
        } else {
            cout << "Contact doesn't exist. \n";
        }

        break;
    default:
        cout << "Invalid choice! \n";
    }

    if (updated) {
        cout << "Contact updated successfully! \n";
    }
}

void searchContact(const map<string, string> &contacts)
{
    string name;

    if (contacts.empty()){
        cout << "No contacts available. Please add a contact first.\n";
        return;
    }

    cout << "Enter name of contact you want to search: ";
    getline(cin, name);

    auto it = contacts.find(name);

    if (it != contacts.end()) {
        cout << it->first << ": " << it->second << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void displayContact(const map<string, string> &contacts)
{
    if (contacts.empty()) {
    cout << "No contacts available.\n";
    return;
    }

    cout << "Displaying Contacts... \n";
    for (auto p : contacts) {
        cout << p.first << ": " << p.second << endl;
    }
}
void choiceAction(int choice, map<string, string> &contacts)
{
    // string name , phoneNumer;
    switch (choice)
    {
    case 1:
        addContact(contacts);
        break;
    case 2:
        deleteContact(contacts);
        break;
    case 3:
        updateContact(contacts);
        break;
    case 4:
        searchContact(contacts);
        break;
    case 5:
        displayContact(contacts);
        break;
    case 6:
        cout << "Good Bye! \n";
        break;
    default:
        cout << "Invalid choice! \n";
        break;
    }
}

int main()
{

    /*C++ 4 phase roadmap - phase 1: Easy Projects - Project4: Contact Book Implementation*/

    map<string, string> contacts; // Store names and phone numbers using a map

    int choice;
    do {
        showMenu();
        choice = selectChoice();

        choiceAction(choice, contacts);

    } while (choice != 6);

    return 0;
}
