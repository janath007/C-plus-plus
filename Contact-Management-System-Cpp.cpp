#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

void saveContact(const Contact& c) {
    ofstream file("contacts.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    file << c.name << "," << c.phone << "," << c.email << "\n";
    file.close();
}

void viewContacts() {
    ifstream file("contacts.txt");
    if (!file) {
        cout << "No contacts found.\n";
        return;
    }

    string line;
    cout << "\n==== CONTACT LIST ====\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void searchContact(const string& name) {
    ifstream file("contacts.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(name) != string::npos) {
            cout << "Found: " << line << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with name: " << name << "\n";

    file.close();
}

void deleteContact(const string& name) {
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    bool deleted = false;
    string line;

    while (getline(file, line)) {
        if (line.find(name) == string::npos) {
            temp << line << "\n";
        } else {
            deleted = true;
        }
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (deleted)
        cout << "Contact deleted!\n";
    else
        cout << "Contact not found.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        cin.ignore(); 

        if (choice == 1) {
            Contact c;
            cout << "Enter name: ";
            getline(cin, c.name);
            cout << "Enter phone: ";
            getline(cin, c.phone);
            cout << "Enter email: ";
            getline(cin, c.email);

            saveContact(c);
            cout << "Contact saved!\n";
        }
        else if (choice == 2) {
            viewContacts();
        }
        else if (choice == 3) {
            string name;
            cout << "Enter name to search: ";
            getline(cin, name);
            searchContact(name);
        }
        else if (choice == 4) {
            string name;
            cout << "Enter name to delete: ";
            getline(cin, name);
            deleteContact(name);
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

