#include "contact.hpp"
#include <iostream>

void Contact::setFirstName( void ) {
    std::string first_name;
    
    std::cout << "First name: ";
    
    std::cin >> first_name;
    
    _first_name = first_name;
}

std::string Contact::getFirstName() {
    return _first_name;
}

void Contact::setLastName(std::string last_name) {
    _last_name = last_name;
}

std::string Contact::getLastName() {
    return _last_name;
}

void Contact::setNickName(std::string nickname) {
    _nickname = nickname;
}

std::string Contact::getNickName() {
    return _nickname;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
    _darkest_secret = darkest_secret;
}

std::string Contact::getDarkestSecret() {
    return _darkest_secret;
}
