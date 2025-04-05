#include "phoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {} // constructeur de la classe PhoneBook: initialise les attributs
									 // il peut aussi allouer des ressources dynamiques si necessaire,
									 // ouvrir des fichiers, etablir des connections reseau...
									 // il n'a pas de type de retour.
									 // s'il n'est pas parametre, le compilateur le generera par defaut,
									 // sans rien initialiser

PhoneBook::~PhoneBook() {} // destructeur: sert a liberer les ressources allouees (non necessaire
						   // si pas d'allocation dynamique, mais bonne pratique)


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

void	PhoneBook::displayContacts() const // methode constante = ne peut pas modifier l'objet de sa classe
										   // cependant, elle peut appeler une fonction non constante, qui
										   // elle pourra modifier l'objet
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
