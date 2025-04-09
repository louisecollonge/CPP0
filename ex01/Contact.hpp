#ifndef CONTACT_HPP
#define CONTACT_HPP

#define BLUE		"\033[94m"
#define TURQUOISE	"\033[38;5;49m"
#define ORANGE		"\033[38;5;214m"
#define BOLD_RED 	"\033[1;31m"
#define RESET		"\033[0m"

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
	private:

		std::string	firstName;
		std::string lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:

		Contact();
		~Contact();
		void		setContact(const std::string &first, const std::string &last, 
							const std::string &nick, const std::string &phone,
							const std::string &secret);
		void		displayContact(int index) const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif
