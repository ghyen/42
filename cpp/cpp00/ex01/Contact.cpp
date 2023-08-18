#include "Contact.hpp"

// Getter functions
std::string Contact::get_first_name() {
    return first_name;
}

std::string Contact::get_last_name() {
    return last_name;
}

std::string Contact::get_nickname() {
    return nickname;
}

std::string Contact::get_phone_number() {
    return phone_number;
}

std::string Contact::get_darkest_secret() {
    return darkest_secret;
}

// Setter functions
void Contact::set_first_name(const std::string& fname) {
    first_name = fname;
}

void Contact::set_last_name(const std::string& lname) {
    last_name = lname;
}

void Contact::set_nickname(const std::string& nname) {
    nickname = nname;
}

void Contact::set_phone_number(const std::string& pnum) {
    phone_number = pnum;
}

void Contact::set_darkest_secret(const std::string& secret) {
    darkest_secret = secret;
}
