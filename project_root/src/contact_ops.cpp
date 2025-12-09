#include "contact_ops.h"
#include "contact.h"

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
