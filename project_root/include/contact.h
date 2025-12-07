#ifndef CONTACT_H
#define CONTACT_H

#include <string>

struct Contact {
    int id;
    std::string name;
    std::string phone;
    std::string category;
    std::string birthday;
    int age;
    bool deleted;
};

extern const int MAX_CONTACTS;
extern Contact contacts[];
extern int contactsCount;

#endif
