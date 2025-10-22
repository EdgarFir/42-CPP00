#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook() : _nbContacts(0), _lastContactIndexAdded(0)
{
    std::cout << "\n>> Phonebook initiated <<\n\n";
}

Phonebook::~Phonebook()
{
    std::cout << ">> Phonebook turned off <<\n";
}

std::string Phonebook::getPromptRes(std::string prompt)
{
	std::string res;

	std::cout << prompt;
	std::getline(std::cin, res);

	return res;
}

void printCol(std::string field, int colIndex)
{
	if (field.size() > 10) field = field.substr(0, 9) + ".";

	std::cout << std::setw(10) << field;

	if (colIndex != 3)
		std::cout << "|";
	else
		std::cout << "\n";
}

bool Phonebook::showContactInfo(std::string index)
{
	if (!(index.size() == 1 && isdigit(index[0])))
		throw std::runtime_error("Invalid index\n");
	int nIndex;

	nIndex = std::atoi(index.c_str());

	if (!(nIndex >= 1 && nIndex <= MAX_CONTACTS)) 
		throw std::runtime_error("Invalid index range\n");
	if (nIndex > _nbContacts)
		throw std::runtime_error("Contact index does not exist\n");

	std::cout 
		<< "Last name: " << _list[nIndex - 1].getId() << "\n"
		<< "First name: " << _list[nIndex - 1].getFirstName() << "\n"
		<< "Last name: " << _list[nIndex - 1].getLastName() << "\n"
		<< "Nickname: " << _list[nIndex - 1].getNickname() << "\n"
		<< "Darkest secret: " << _list[nIndex - 1].getDarkestSecret() << "\n"
		<< "Phonenumber: " << _list[nIndex - 1].getPhonenumber() << "\n"
	<< "\n";

	return true;
}

void Phonebook::searchContacts()
{
	if (!_nbContacts)
	{
		std::cout << "\n>> No contacts added. Type ADD in main menu <<\n\n";
		return ;
	}
	std::cout << "\n>> Search contact << \n\n";

	printCol("Index", 0);
	printCol("First name", 1);
	printCol("Last name", 2);
	printCol("Nickname", 3);
	
	for (int i = 0; i < _nbContacts; i++)
	{
		// Convert integer to string
		std::ostringstream stream; // Criar objecto osstream
		stream << _list[i].getId(); // Enviar id para esse objeto
		printCol(stream.str(), 0); // Converte lo para string

		printCol(_list[i].getFirstName(), 1);
		printCol(_list[i].getLastName(), 2);
		printCol(_list[i].getNickname(), 3);
	}
	
	while (true)
	{
		try
		{
			showContactInfo(getPromptRes("\nType contact index to show information: "));
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << "Type from 1 - " << _nbContacts << "\n";
			continue;
		}
		break ;
	}
}

void Phonebook::addContact()
{
	Contact new_contact;

	std::cout << "\n>> Add contact << \n";
	new_contact.setFirstName(getPromptRes("First name: "));
	new_contact.setLastName(getPromptRes("Last name: "));
	new_contact.setNickname(getPromptRes("Nickname: "));
	new_contact.setDarkestSecret(getPromptRes("Darkest secret: "));
	new_contact.setPhonenumber(getPromptRes("Phonenumber: "));
	new_contact.setId(_nbContacts + 1);

	_list[_lastContactIndexAdded] = new_contact;
	_lastContactIndexAdded = (_lastContactIndexAdded + 1) % MAX_CONTACTS;
	if (_nbContacts < MAX_CONTACTS)
		_nbContacts++;
	std::cout << ">> Contact added with success <<\n\n"; 
}

void Phonebook::phonebookLoop()
{
	std::string option;

	while (option != "EXIT")
	{
		option = getPromptRes("ADD - SEARCH - EXIT\nType an option: ");

		if (option == "ADD")
			addContact();
		else if (option == "SEARCH")
			searchContacts();
	}
}
