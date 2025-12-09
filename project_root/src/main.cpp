#include <iostream>
#include "contact.h"
#include "input.h"
#include "output.h"
#include "file_io.h"
#include "tree.h"
#include "contact.h"


using namespace std;

void printMenu() {
    cout << "\n====== MENU ======\n";
    cout << "1. Add contact\n";
    cout << "2. Show all contacts\n";
    cout << "3. Save to file\n";
    cout << "4. Load from file\n";
    cout << "5. Build ID index (binary tree)\n";
    cout << "6. Show contacts ascending (by ID)\n";
    cout << "7. Show contacts descending (by ID)\n";
    cout << "8. Search (recursive)\n";
    cout << "9. Search (iterative)\n";
    cout << "0. Exit\n";
    cout << "==================\n";
    cout << "Choose option: ";
}


void buildIdIndex(BinaryTreeIndex& index) {
    index = BinaryTreeIndex(); // сброс
    for (int i = 0; i < contactsCount; i++) {
        if (!contacts[i].deleted) {
            index.insert(i, contacts[i].id);
        }
    }
}


int main() {
    BinaryTreeIndex idIndex;  // дерево для индексации по ID
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
        else if (choice == 3) {
            cout << "Enter file name: ";
            string filename;
            getline(cin, filename);
        
            cout << "Choose mode (1 — new file, 2 — append): ";
            int mode;
            cin >> mode;
            cin.ignore();
        
            if (saveToFile(filename, mode)) {
                cout << "Saved successfully!\n";
            } else {
                cout << "Save error!\n";
            }
        }
        else if (choice == 4) {
            cout << "Enter file name: ";
            string filename;
            getline(cin, filename);
        
            resetContacts();  // <<< ВАЖНО: очищаем массив перед загрузкой
            idIndex = BinaryTreeIndex();  // сброс индекса

            if (loadFromFile(filename)) {
                cout << "Loaded successfully!\n";

                // Автоматическая перестройка индекса
                idIndex = BinaryTreeIndex(); 
                buildIdIndex(idIndex);
                cout << "Index rebuilt successfully after loading.\n";

            } else {
                cout << "Error while loading!\n";
            }
        }

        else if (choice == 5) {
            buildIdIndex(idIndex);
            cout << "Index (binary tree) built successfully!\n";
        }
        else if (choice == 6) {
            cout << "\n--- Contacts ascending by ID ---\n";
            idIndex.printAscending();
        }
        else if (choice == 7) {
            cout << "\n--- Contacts descending by ID ---\n";
            idIndex.printDescending();
        }
        else if (choice == 8) {
            int key;
            cout << "Enter ID to search (recursive): ";
            cin >> key;
            cin.ignore();
        
            TreeNode* result = idIndex.searchRecursive(idIndex.getRoot(), key);
        
            if (result == nullptr) {
                cout << "Contact not found.\n";
            } else {
                int i = result->contactIndex;
                printContact(contacts[i]);
            }
        }
        else if (choice == 9) {
            int key;
            cout << "Enter ID to search (iterative): ";
            cin >> key;
            cin.ignore();
        
            TreeNode* result = idIndex.searchIterative(key);
        
            if (result == nullptr) {
                cout << "Contact not found.\n";
            } else {
                int i = result->contactIndex;
                printContact(contacts[i]);
            }
        }

        else if (choice == 0) {
            cout << "Exiting...\n";
            break; // завершение программы
        }
        else {
            cout << "Invalid option, try again!\n";
        }
    }
    return 0;
}