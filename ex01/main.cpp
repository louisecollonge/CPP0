#include "phoneBook.hpp"

static std::string	notEmpty(const std::string entry)
{
	std::string	input;

	do
	{
		std::cout << BLUE << entry << RESET;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << ORANGE << "Field cannot be empty" << RESET << std::endl;
	} while (input.empty());
	return (input);
}

static int	addContact(PhoneBook &phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	std::cout << std::endl;
	firstName = notEmpty("\tFirst Name: ");
	lastName = notEmpty("\tLast Name: ");
	nickname = notEmpty("\tNickname: ");
	phoneNumber = notEmpty("\tPhone number: ");
	secret = notEmpty("\tDarkest secret: ");
	phoneBook.addContact(firstName, lastName, nickname, phoneNumber, secret);
	std::cout << std::endl;
	return (1);
}

static void	searchContact(PhoneBook	&phoneBook, int nbContacts)
{
	std::string	indexStr;
	int			i;
	
	phoneBook.displayContacts();
	while (1)
	{
		std::cout << TURQUOISE << "Enter the index of the contact you want: " << RESET;
		std::getline(std::cin, indexStr);
		i = std::atoi(indexStr.c_str());
		if (nbContacts == 0)
		{
			std::cout << ORANGE << "Phone book is empty" << RESET << std::endl;
			break ;
		}
		if (indexStr.length() != 1 || !std::isdigit(indexStr[0]) || (i < 0 || i >= nbContacts))
			std::cout << ORANGE << "Wrong index" << RESET << std::endl;
		else
		{
			std::cout << std::endl;
			phoneBook.displayContact(i);
			std::cout << std::endl;
			break ;
		}
	}
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;
	int			nbContacts = 0;

	while (1)
	{
		std::cout << TURQUOISE << "Enter a command (ADD, SEARCH or EXIT): " << RESET ;
		std::getline(std::cin, command);
		if (command == "ADD")
			nbContacts += addContact(phoneBook);
		else if (command == "SEARCH")
			searchContact(phoneBook, nbContacts);
		else if (command == "EXIT")
		{
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			break ;
		}
		else
			continue ;
	}
	return (0);
}
