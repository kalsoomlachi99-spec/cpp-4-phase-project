#include <iostream>
#include <vector>

using namespace std;

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

void deleteContact(vector<string>& names, vector<string>& phoneNumbers, string& name, string& phoneNumber){
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


int main() {
    
    /*C++ 4 phase roadmap - phase 1: Easy Projects - Project4: Contact Book Implementation*/

    // Step 1: Store names  and phone numbers using vectors
    vector<string> names;
    vector<string> phoneNumbers;
    string name, phoneNumber;

    addContact(names, phoneNumbers, name, phoneNumber);

    deleteContact(names, phoneNumbers, name, phoneNumber);

    return 0;
}
