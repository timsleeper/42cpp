#include <iostream>
#include <string>
#include <limits>
#include "phonebook.hpp"
#include "contact.hpp"

bool read_non_empty_input(std::string &input, const std::string &prompt)
{
    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << std::endl
                  << "Empty values are invalid. Exiting." << std::endl;
        return false;
    }
    return !input.empty();
}

// Adds a new contact to the phonebook
void add_contact(PhoneBook &phonebook)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    if (!read_non_empty_input(first_name, "Enter the first name: "))
        return;
    if (!read_non_empty_input(last_name, "Enter the last name: "))
        return;
    if (!read_non_empty_input(nickname, "Enter the nickname: "))
        return;
    if (!read_non_empty_input(phone_number, "Enter the phone number: "))
        return;
    if (!read_non_empty_input(darkest_secret, "Enter the darkest secret: "))
        return;

    Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    phonebook.add_contact(new_contact);
}

// Searches for a contact in the phonebook and displays its details
void search_contact(PhoneBook &phonebook)
{
    phonebook.display_contacts();

    int index;
    std::cout << "Enter the index of the contact to display: ";

    while (!(std::cin >> index))
    {
        if (std::cin.eof())
        {
            return;
        }
        std::cout << "Invalid input. Please enter a valid index: ";
        std::cin.clear();                                                   // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
    }
    std::cin.ignore(); // Ignore the remaining newline character
    phonebook.display_contact_details(index);
}

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        if (!read_non_empty_input(command, "Please enter a command (ADD, SEARCH, or EXIT): "))
        {
            break;
        }

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
