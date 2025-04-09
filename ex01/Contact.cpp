#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const { return (firstName); }
std::string	Contact::getLastName() const { return (lastName); }
std::string	Contact::getNickname() const { return (nickname); }
std::string	Contact::getPhoneNumber() const { return (phoneNumber); }
std::string	Contact::getDarkestSecret() const { return (darkestSecret); }

std::string	truncate(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::setContact(const std::string &first, const std::string &last, 
					const std::string &nick, const std::string &phone,
					const std::string &secret)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void	Contact::displayContact(int index) const
{
	std::cout << std::setw(10) << std::right << index << "|"
			  << std::setw(10) << std::right << truncate(firstName) << "|"
			  << std::setw(10) << std::right << truncate(lastName) << "|"
			  << std::setw(10) << std::right << truncate(nickname) << std::endl;
}
