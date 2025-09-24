#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>

void add_contact(Phonebook *phonebook){
    int contact_index = phonebook->contacts;

    phonebook->list[contact_index].setFirstName();
}

int main (void) {
    // Object Phonebook class 
    Phonebook phonebook;
    
    // Object String class that will save the prompt from user
    std::string prompt;

    // Run app till user prompt EXIT
    while (prompt != "EXIT")
    {
        // Prompt user and save.
        std::cin >> prompt;

        // If user want to ADD contact
        if (prompt == "ADD")
            add_contact(&phonebook);
        std::cout << "Firstname: " << phonebook.list[0].getFirstName() << std::endl;
        break ;
        // std::cout << prompt << std::endl;
    }
}