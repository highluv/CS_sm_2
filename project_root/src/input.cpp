#include <iostream>
#include <string>
#include "input.h"

Contact inputContact() {
    Contact c;

    std::cout << "Input contacts id: ";
    std::cin >> c.id;
    std::cin.ignore(); 

    std::cout << "Input contacts name: ";
    std::getline(std::cin, c.name);

    std::cout << "Input contacts phone: ";
    std::getline(std::cin, c.phone);

    std::cout << "Input contacts category: ";
    std::getline(std::cin, c.category);

    std::cout << "Input contacts birthday: ";
    std::getline(std::cin, c.birthday);

    std::cout << "Input contacts age: ";
    std::cin >> c.age;
    std::cin.ignore();

    c.deleted = false;
    return c;
}
