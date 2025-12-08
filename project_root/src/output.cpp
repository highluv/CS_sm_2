#include <iostream>
#include "output.h"
#include "contact.h"

void printContact(const Contact& c) {
    std::cout << "ID:        " << c.id << "\n";
    std::cout << "Name:      " << c.name << "\n";
    std::cout << "Phone:     " << c.phone << "\n";
    std::cout << "Category:  " << c.category << "\n";
    std::cout << "Birthday:  " << c.birthday << "\n";
    std::cout << "Age:       " << c.age << "\n";
    std::cout << "Deleted?:  " << (c.deleted ? "yes" : "no") << "\n";
    std::cout << "------------------------\n";
}

void printContacts() {
    for (int i = 0; i < contactsCount; i++) {
        if (!contacts[i].deleted) {
            printContact(contacts[i]);
        }
    }
}
