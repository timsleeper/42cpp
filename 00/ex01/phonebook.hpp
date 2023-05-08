#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
public:
    // Constructor
    PhoneBook();

    // Adds a contact to the phonebook
    void add_contact(Contact new_contact);

    // Displays the summary of all contacts in the phonebook
    void display_contacts() const;

    // Displays the details of a contact with the given index
    void display_contact_details(int index) const;

private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int contact_count;
};

#endif
