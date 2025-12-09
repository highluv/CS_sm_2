#include <iostream>
#include <limits>
#include "contact_ops.h"
#include "contact.h"

using namespace std;


bool deleteById(int id) {
    for (int i = 0; i < contactsCount; i++) {
        if (contacts[i].id == id) {
            contacts[i].deleted = true;
            return true;
        }
    }
    return false; // не найден
}

void compactContacts() {
    int newCount = 0;

    for (int i = 0; i < contactsCount; i++) {
        if (!contacts[i].deleted) {
            contacts[newCount++] = contacts[i];
        }
    }

    contactsCount = newCount;
}

bool editContactById(int id) {
    for (int i = 0; i < contactsCount; i++) {
        if (contacts[i].id == id && !contacts[i].deleted) {
            cout << "Editing contact with ID = " << id << "\n";

            string newValue;

            //  Edit Name 
            cout << "Current name: " << contacts[i].name << "\n";
            cout << "New name (enter to keep): ";
            getline(cin, newValue);
            if (!newValue.empty()) contacts[i].name = newValue;

            //  Edit Phone 
            cout << "Current phone: " << contacts[i].phone << "\n";
            cout << "New phone (enter to keep): ";
            getline(cin, newValue);
            if (!newValue.empty()) contacts[i].phone = newValue;

            //  Edit Category 
            cout << "Current category: " << contacts[i].category << "\n";
            cout << "New category (enter to keep): ";
            getline(cin, newValue);
            if (!newValue.empty()) contacts[i].category = newValue;

            //  Edit Birthday 
            cout << "Current birthday: " << contacts[i].birthday << "\n";
            cout << "New birthday (enter to keep): ";
            getline(cin, newValue);
            if (!newValue.empty()) contacts[i].birthday = newValue;

            //  Edit Age 
            cout << "Current age: " << contacts[i].age << "\n";
            cout << "New age (enter to keep): ";
            getline(cin, newValue);
            if (!newValue.empty()) contacts[i].age = stoi(newValue);

            cout << "Contact updated successfully.\n";
            return true;
        }
    }
    return false;
}

