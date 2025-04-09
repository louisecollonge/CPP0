#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(const std::string &first, const std::string &last, 
		const std::string &nick, const std::string &phone, const std::string &secret,
		int &nbContacts)
{
	index = nbContacts % 8;
	contacts[index].setContact(first, last, nick, phone, secret);
	index++;
	nbContacts++;
}

void	PhoneBook::displayContacts(int nbContacts) const
{
	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|"
			  << std::setw(10) << std::right << "First name" << "|"
			  << std::setw(10) << std::right << "Last name" << "|"
			  << std::setw(10) << std::right << "Nickname" << std::endl;
	if (nbContacts > 8)
		nbContacts = 8;
	for (int i = 0; i < nbContacts ; i++) {
		contacts[i].displayContact(i);
	}
	std::cout << std::endl;
}

void	PhoneBook::displayContact(int i) const
{
	std::cout << BLUE << " First name: " << RESET << contacts[i].getFirstName() << std::endl;
	std::cout << BLUE << " Last name: " << RESET << contacts[i].getLastName() << std::endl;
	std::cout << BLUE << " Nickname: " << RESET << contacts[i].getNickname() << std::endl;
	std::cout << BLUE << " Phone number: " << RESET << contacts[i].getPhoneNumber() << std::endl;
	std::cout << BLUE << " Darkest secret: " << RESET << contacts[i].getDarkestSecret() << std::endl;
}
