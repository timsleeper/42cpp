#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

// Constructor
PhoneBook::PhoneBook() : contact_count(0) {}

// Adds a contact to the phonebook
void PhoneBook::add_contact(Contact new_contact)
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

// Displays the summary of all contacts in the phonebook
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

// Displays the details of a contact with the given index
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
