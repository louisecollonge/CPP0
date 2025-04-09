#include "PhoneBook.hpp"

static std::string	notEmpty(const std::string entry)
{
	std::string	input;

	do
	{
		std::cout << BLUE << entry << RESET;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			exit(0) ;
		}						   
		if (input.empty())
			std::cerr << ORANGE << "Field cannot be empty" << RESET << std::endl;
	} while (input.empty());
	return (input);
}

static bool	isCorrectNumber(std::string &phoneNumber)
{
	int	start = 0;

	if (phoneNumber[0] == '+')
		start = 1;
	if (phoneNumber[0] == '+' && phoneNumber[1] == '\0')
	{
		std::cerr << ORANGE << "Please enter digits" << RESET << std::endl;
		return (false);
	}
	for (size_t i = start; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cerr << ORANGE << "Please enter digits without spaces" << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

static int	addContact(PhoneBook &phoneBook, int &nbContacts)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	std::cout << std::endl;
	firstName = notEmpty(" First Name: ");
	lastName = notEmpty(" Last Name: ");
	nickname = notEmpty(" Nickname: ");
	phoneNumber = notEmpty(" Phone number: ");
	while (!isCorrectNumber(phoneNumber))
		phoneNumber = notEmpty(" Phone number: ");
	secret = notEmpty(" Darkest secret: ");
	phoneBook.addContact(firstName, lastName, nickname, phoneNumber, secret, nbContacts);
	std::cout << std::endl;
	return (nbContacts);
}

static void	searchContact(PhoneBook	&phoneBook, int nbContacts)
{
	std::string	indexStr;
	int			i;
	
	if (nbContacts == 0)
	{
		std::cerr << ORANGE << "Phone book is empty" << RESET << std::endl;
		return ;
	}
	phoneBook.displayContacts(nbContacts);
	while (1)
	{
		std::cout << TURQUOISE << "Enter the index of the contact you want: " << RESET;
		if (!std::getline(std::cin, indexStr))
		{
			std::cout << std::endl;
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			exit(0);
		}
		i = std::atoi(indexStr.c_str());
		if (indexStr.length() != 1 || !std::isdigit(indexStr[0]) || (i < 0 || i >= nbContacts))
			std::cerr << ORANGE << "Wrong index, try again" << RESET << std::endl;
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
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			break ;
		}
		if (command == "ADD")
			nbContacts = addContact(phoneBook, nbContacts);
		else if (command == "SEARCH")
			searchContact(phoneBook, nbContacts);
		else if (command == "EXIT")
		{
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			break ;
		}
		else
			std::cout << ORANGE << "Wrong command" << RESET << std::endl ;
	}
	return (0);
}
