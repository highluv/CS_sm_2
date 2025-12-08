#include <iostream>
#include "contact.h"
#include "input.h"
#include "output.h"

using namespace std;

void printMenu() {
    cout << "\n====== MENU ======\n";
    cout << "1. Add contact\n";
    cout << "2. Show all contacts\n";
    cout << "0. Exit\n";
    cout << "==================\n";
    cout << "Choose option: ";
}

int main() {
    while (true) {
        printMenu();

        int choice;
        cin >> choice;
        cin.ignore(); // чтобы съесть \n

        if (choice == 1) {
            cout << "\n--- Add Contact ---\n";
            Contact c = inputContact();
            contacts[contactsCount++] = c;
            cout << "Contact added!\n";
        }
        else if (choice == 2) {
            cout << "\n--- Contact List ---\n";
            printContacts();
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
            break; // выход из цикла → завершение программы
        }
        else {
            cout << "Invalid option, try again!\n";
        }
    }
    return 0;
}