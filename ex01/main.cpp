#include "phoneBook.hpp"

static std::string	notEmpty(const std::string entry)
{
	std::string	input;

	do
	{
		std::cout << BLUE << entry << RESET;
		if (!std::getline(std::cin, input)) // objet de flux "cin" = character input
											// getline() est une fonction non membre appartenant au namespace std
		{
			std::cout << std::endl;
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			exit(0) ;
		}						   
		if (input.empty()) // .empty() est une fn membre de la classe string, qui appartient au namespace std
						   // .empty() ne peut prendre en argument que des objets de la classe string
			std::cerr << ORANGE << "Field cannot be empty" << RESET << std::endl; // "cerr" = character error
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
		std::cerr << ORANGE << "Please enter only digits w/o spaces" << RESET << std::endl;
		return (false);
	}
	for (size_t i = start; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cerr << ORANGE << "Please enter only digits w/o spaces" << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

static int	addContact(PhoneBook &phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	std::cout << std::endl; // endl manipule un flux ; le flux est dirige par cout
	firstName = notEmpty("\tFirst Name: ");
	lastName = notEmpty("\tLast Name: ");
	nickname = notEmpty("\tNickname: ");
	phoneNumber = notEmpty("\tPhone number: ");
	while (!isCorrectNumber(phoneNumber))
		phoneNumber = notEmpty("\tPhone number: ");
	secret = notEmpty("\tDarkest secret: ");
	phoneBook.addContact(firstName, lastName, nickname, phoneNumber, secret); // fn membre de la classe PhoneBook
	std::cout << std::endl;
	return (1);
}

static void	searchContact(PhoneBook	&phoneBook, int nbContacts)
{
	std::string	indexStr; // chaine de char, mais pas sous forme de pointeur vers un tableau de char
	int			i;
	
	phoneBook.displayContacts();
	while (1)
	{
		std::cout << TURQUOISE << "Enter the index of the contact you want: " << RESET;
		if (!std::getline(std::cin, indexStr))
		{
			std::cout << std::endl;
			std::cout << BOLD_RED << "Exiting... " << RESET << std::endl;
			exit(0) ; // ne fait pas partie de std::
		}
		i = std::atoi(indexStr.c_str()); // atoi est une fn non membre appartenant au namespace std
										 // .c_str() est une methode (fn membre) de la classe string qui appartient au namespace std
										 // .c_str() cree un pointeur vers un tableau de char qui represente la chaine indexStr
		if (nbContacts == 0)
		{
			std::cerr << ORANGE << "Phone book is empty" << RESET << std::endl;
			break ;
		}
		if (indexStr.length() != 1 || !std::isdigit(indexStr[0]) || (i < 0 || i >= nbContacts))
			std::cerr << ORANGE << "Wrong index" << RESET << std::endl;
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
