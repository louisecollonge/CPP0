#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(const std::string &first, const std::string &last, 
						const std::string &nick, const std::string &phone,
						const std::string &secret, int &nbContacts);
		void	displayContacts(int nbContacts) const;
		void	displayContact(int i) const;
};

#endif
