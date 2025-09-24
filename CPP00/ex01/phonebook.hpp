#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
    public:
        Contact list[8];
        int     contacts;

    Phonebook() {
        contacts = 0;
    }
};

#endif