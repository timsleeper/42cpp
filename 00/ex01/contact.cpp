#include <iostream>
#include <iomanip>
#include "contact.hpp"

// Default constructor
Contact::Contact() {}

// Constructor with parameters for contact details
Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string phone_number,
                 std::string darkest_secret)
    : first_name(first_name), last_name(last_name), nickname(nickname),
      phone_number(phone_number), darkest_secret(darkest_secret) {}

// Displays a single field of the contact with proper formatting
void Contact::display_field(std::string field) const
{
    if (field.length() > 10)
    {
        std::cout << std::setw(10) << field.substr(0, 9) + ".";
    }
    else
    {
        std::cout << std::setw(10) << field;
    }
    std::cout << '|';
}

// Displays the summary of the contact
void Contact::display_summary() const
{
    display_field(first_name);
    display_field(last_name);
    display_field(nickname);
}

// Displays the full details of the contact
void Contact::display_full() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
