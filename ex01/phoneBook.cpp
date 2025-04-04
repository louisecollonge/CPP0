#include "phoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(const std::string &first, const std::string &last, 
		const std::string &nick, const std::string &phone,
		const std::string &secret)
{
	if (index < 8) {
		contacts[index].setContact(first, last, nick, phone, secret);
		index++;
	}
	else
		contacts[index - 1].setContact(first, last, nick, phone, secret);
}

void	PhoneBook::displayContacts() const
{
	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|"
			  << std::setw(10) << std::right << "First name" << "|"
			  << std::setw(10) << std::right << "Last name" << "|"
			  << std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < index ; i++) {
		contacts[i].displayContact(i);
	}
	std::cout << std::endl;
}

void	PhoneBook::displayContact(int i) const
{
	std::cout << BLUE << "\tFirst name: " << RESET << contacts[i].getFirstName() << std::endl;
	std::cout << BLUE << "\tLast name: " << RESET << contacts[i].getLastName() << std::endl;
	std::cout << BLUE << "\tNickname: " << RESET << contacts[i].getNickname() << std::endl;
	std::cout << BLUE << "\tPhone number: " << RESET << contacts[i].getPhoneNumber() << std::endl;
	std::cout << BLUE << "\tDarkest secret: " << RESET << contacts[i].getDarkestSecret() << std::endl;
}
