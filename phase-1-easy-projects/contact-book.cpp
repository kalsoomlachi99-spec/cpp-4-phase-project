#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int getValidInt() {

    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}

void showMenu(){
    cout << " ====== Contact Book ====== " << endl;

    cout << " 1. Add Contact \n";
    cout << " 2. Delete Contact \n";
    cout << " 3. Update Contact \n";
    cout << " 4. Search Contact \n";
    cout << " 5. Display Contact \n";
    cout << " 6. Exit \n";

}

void selectChoice(){
    cout << "Enter your choice: ";
    int choice = getValidInt();
}

int linearSearch(vector <string>& names, string& targetName){
    for (int i = 0; i < names.size(); i++){
        if(names[i] == targetName) {
            return i;
        }
    }
    return -1;
}

void addContact(vector<string>& names, vector<string>& phoneNumbers, string& name, string& phoneNumber) {
    cout << "Enter name of contact: ";
    getline(cin, name);
    names.push_back(name);

    cout << "Enter phone number of contact: ";
    getline(cin, phoneNumber);
    phoneNumbers.push_back(phoneNumber);
}

void deleteContact(vector<string>& names, vector<string>& phoneNumbers, string& name){
    if(names.empty()){
        cout << "No contact to delete \n";
        return;
    }

    cout << "Which contact you want to delete (please enter exact name): ";
    getline(cin, name);

    int index = linearSearch(names, name);

    if(index != -1) {
        names.erase(names.begin() + index);
        phoneNumbers.erase(phoneNumbers.begin() + index);

        cout << "Deleted Successfully! \n";
    } else {
        cout << "Invalid contact! \n";
    }
    
}

void updateContact (vector <string>& names,vector<string>& phoneNumbers, string& name, string& phoneNumber){
    cout << "Enter the exact name of contact you want to update: ";
    cin >> name;

    cout << "Update name: ";
    cout << "Update phone number: ";
    
}

void chioceAction(const int &choice, vector <string>& names,vector<string>& phoneNumbers, string& name, string& phoneNumber){
    switch (choice){
        case 1: 
            addContact(names, phoneNumbers, name, phoneNumber);
            break;
        case 2:
            deleteContact(names, phoneNumbers, name);
            break;
        case 3:
            updateContact(names, phoneNumbers, name, phoneNumber);
            break;
        case 4:
            searchContact(names, phoneNumbers, name);
            break;
        case 5:
            displayContact(names, phoneNumbers, name, phoneNumber);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice! \n";
            break;
    }
}

int main() {
    
    /*C++ 4 phase roadmap - phase 1: Easy Projects - Project4: Contact Book Implementation*/

    // Step 1: Store names  and phone numbers using vectors
    vector<string> names;
    vector<string> phoneNumbers;
    string name, phoneNumber;
    int choice;
    
    showMenu();

    
    return 0;
}
