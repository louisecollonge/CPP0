#include "phoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook; // cree une instance de la classe PhoneBook
	std::string	command;

	while (1){
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD"){
			std::string	firstName;
			std::cout << TURQUOISE << "First Name: ";
			std::getline(std::cin, firstName);
			std::string	lastName;
			std::cout << "Last Name: ";
			std::getline(std::cin, lastName);
			std::string	nickname;
			std::cout << "Nickname: ";
			std::getline(std::cin, nickname);
			std::string	phoneNumber;
			std::cout << "Phone number: ";
			std::getline(std::cin, phoneNumber);
			std::string	secret;
			std::cout << "Darkest secret: ";
			std::getline(std::cin, secret);
			std::cout << RESET;

			phoneBook.addContact(firstName, lastName, nickname, phoneNumber, secret);
		}
		else if (command == "SEARCH") {
			phoneBook.displayContacts();
		}
		else if (command == "EXIT") {
			std::cout << MAGENTA << "Exiting... " << RESET << std::endl;
			break ;
		}
		else {
			std::cout << RED << "Wrong command" << RESET << std::endl;
		}
	}




/* 	phoneBook.addContact("Louise", "Collonge", "Culbuto", "01234", "j'ai un lapin qui s'appelle une mouche");
	phoneBook.addContact("Guillaume", "Despont", "Guimo Pedon", "56789", "je s'appelle Grout");
	phoneBook.addContact("Jean-Philibert", "Tirtir", "J'en fi", "42", "je suis un brigand");
	phoneBook.addContact("Sebastienne", "Boustifloupe", "Sebastiennette", "12", "mes parents hesitaient avec Etienne");
	phoneBook.addContact("Kamyll", "De La Motte", "la grosse Came", "888", "i like trains");
	phoneBook.addContact("Qwertie", "Clav'yeah", "Qwesh", "84759485", "je suis illettree");
	phoneBook.addContact("Kevin", "Tartuffe", "Truffe", "06556677", "je veux changer de nom");
	phoneBook.addContact("Wrong", "Wrong", "Wrong", "Wrong", "Wrong");
	//9e contact:
	phoneBook.addContact("Machine", "Truc", "Vachette", "010101", "je n'existe pas");
	phoneBook.displayContacts(); */

	return (0);
}
