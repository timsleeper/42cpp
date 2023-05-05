#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    void add_contact(const Contact &new_contact);
    void display_contacts() const;
    void display_contact_details(int index) const;

private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int contact_count;
};

#endif
