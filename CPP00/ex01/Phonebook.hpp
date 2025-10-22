#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class Phonebook {
public:
    Phonebook();
    ~Phonebook();

    void	searchContacts();
	void	phonebookLoop();

private:
    Contact _list[MAX_CONTACTS];
    int			_nbContacts;
	int			_lastContactIndexAdded;

	void		addContact();
	std::string getPromptRes(std::string prompt);
	void		searchContacts();
	bool 		showContactInfo(std::string index);
};
#endif
