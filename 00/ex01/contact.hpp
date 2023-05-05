#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();
    Contact(const std::string &first_name, const std::string &last_name,
            const std::string &nickname, const std::string &phone_number,
            const std::string &darkest_secret);
    void display_summary() const;
    void display_full() const;

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    void display_field(const std::string &field) const;
};

#endif
