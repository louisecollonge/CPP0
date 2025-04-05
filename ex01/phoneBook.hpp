#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8]; // chaque element de ce tableau est une instance de la classe Contact
		int		index;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(const std::string &first, const std::string &last, 
						const std::string &nick, const std::string &phone,
						const std::string &secret);
		void	displayContacts() const;
		void	displayContact(int i) const;
};

#endif
