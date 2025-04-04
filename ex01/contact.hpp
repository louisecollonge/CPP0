#ifndef CONTACT_HPP
#define CONTACT_HPP

#define RED			"\033[91m"
#define GREEN		"\033[92m"
#define YELLOW		"\033[93m"
#define BLUE		"\033[94m"
#define MAGENTA		"\033[95m"
#define RESET		"\033[0m"
#define TURQUOISE	"\033[38;5;49m"
#define ORANGE		"\033[38;5;214m"


#include <iomanip>
#include <iostream>
#include <string>

class Contact {
	private: // prives pour proteger donnees et eviter les modifications directes
	// attributs = variables membres = caracteristiques de l'objet:
		std::string	firstName;
		std::string lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact(); // constructeur
		~Contact(); // destructeur, inutile ici car pas de "new" = allocation dynamique

	// methodes = fonctions membres cad fonction qui appartient et depend de sa classe et peut acceder aux attributs:
		void	setContact(const std::string &first, const std::string &last, 
							const std::string &nick, const std::string &phone,
							const std::string &secret);
		void	displayContact() const;
};

#endif
