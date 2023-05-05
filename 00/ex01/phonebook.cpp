#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::add_contact(const Contact &new_contact)
{
    if (contact_count < MAX_CONTACTS)
    {
        contacts[contact_count++] = new_contact;
    }
    else
    {
        for (int i = 0; i < MAX_CONTACTS - 1; ++i)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[MAX_CONTACTS - 1] = new_contact;
    }
}

void PhoneBook::display_contacts() const
{
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << '|' << std::endl;

    for (int i = 0; i < contact_count; ++i)
    {
        std::cout << std::setw(10) << i << '|';
        contacts[i].display_summary();
        std::cout << std::endl;
    }
}

void PhoneBook::display_contact_details(int index) const
{
    if (index >= 0 && index < contact_count)
    {
        contacts[index].display_full();
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
}
