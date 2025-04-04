#include "contact.hpp"

//constructeur
Contact::Contact() {}

//destructeur
Contact::~Contact() {}

std::string	truncate(const std::string &str) {
	if (str.length() > 10) {
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void	Contact::setContact(const std::string &first, const std::string &last, 
					const std::string &nick, const std::string &phone,
					const std::string &secret) {
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void	Contact::displayContact() const {
	std::cout << std::setw(10) << std::right << truncate(firstName) << "|"
	<< std::setw(10) << std::right << truncate(lastName) << "|"
	<< std::setw(10) << std::right << truncate(nickname) << "|"
	<< std::setw(10) << std::right << truncate(phoneNumber) << "|"
	<< std::setw(10) << std::right << truncate(darkestSecret)
	<< std::endl;
}

