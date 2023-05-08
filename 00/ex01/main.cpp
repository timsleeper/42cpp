#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

// Adds a new contact to the phonebook
void add_contact(PhoneBook &phonebook)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    std::cout << "Enter the first name: ";
    std::getline(std::cin, first_name);

    std::cout << "Enter the last name: ";
    std::getline(std::cin, last_name);

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phone_number);

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, darkest_secret);

    Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    phonebook.add_contact(new_contact);
}

// Searches for a contact in the phonebook and displays its details
void search_contact(PhoneBook &phonebook)
{
    phonebook.display_contacts();

    int index;
    std::cout << "Enter the index of the contact to display: ";

    if (std::cin >> index)
    {
        std::cin.ignore();
        phonebook.display_contact_details(index);
    }
    else
    {
        std::cout << "Invalid input. PLease enter a valid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            add_contact(phonebook);
        }
        else if (command == "SEARCH")
        {
            search_contact(phonebook);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
