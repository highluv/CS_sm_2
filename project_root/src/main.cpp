#include <iostream>
#include "input.h"
#include "contact.h"

int main() {
    std::cout << "Test Contact\n\n";

    Contact c = inputContact();
    contacts[contactsCount++] = c;

    std::cout << "\n--- Вывод контакта ---\n";
    std::cout << "id: " << contacts[0].id << "\n";
    std::cout << "name: " << contacts[0].name << "\n";
    std::cout << "phone: " << contacts[0].phone << "\n";
    std::cout << "category: " << contacts[0].category << "\n";
    std::cout << "birthday: " << contacts[0].birthday << "\n";
    std::cout << "age: " << contacts[0].age << "\n";
    std::cout << "deleted: " << contacts[0].deleted << "\n";

    return 0;
}

