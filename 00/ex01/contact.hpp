#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    // Default constructor
    Contact();

    // Constructor with parameters for contact details
    Contact(std::string first_name, std::string last_name,
            std::string nickname, std::string phone_number,
            std::string darkest_secret);

    // Displays the summary of the contact
    void display_summary() const;

    // Displays the full details of the contact
    void display_full() const;

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    // Displays a single field of the contact with proper formatting
    void display_field(std::string field) const;
};

#endif
