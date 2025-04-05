#include <iostream> // gestion entrees & sorties : objets de flux "cout" et "cin" (dirigent le flux),
					// et manipulateurs de flux "endl", "flush" (modifient le comportement du flux),
					// fonctionnent avec operateur de flux "<<"

#include <string> // classe "std::string", methode (= fn membre) ".length()"

#include <cctype> // fn non membre "std::toupper"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		// "std" = namespace: regroupe des classes, fns, variables... pour eviter conflits de noms
		// par ex. plusieurs namespaces peuvent avoir une fonction appelee "print"
		
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" // objet de flux "cout" = character output
															  // operateur "<<" : dirige donnees vers "cout"
				  << std::endl; // manipulateur de flux de sortie "endl" = end line : '\n' + "flush" (vide buffer de sortie), 
				  				// assure que les donnees soient affichees instantanement
		
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]); // std est un namespace, string est une classe
								// std::string a un constructeur qui cree un objet a partir d'un char*
		
		for (size_t j = 0; j < str.length(); j++) // .length() est une fonction membre (methode) de la classe std::string
			str[j] = std::toupper(str[j]); // on modifie chaque char un par un
		
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
