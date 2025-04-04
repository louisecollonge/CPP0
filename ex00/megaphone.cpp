#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]); // std::string a un constructeur qui cree un objet a partir d'un char*; c'est plus simple pour gerer la memoire associee
		for (size_t j = 0; j < str.length(); j++) // .length() est une fonction  de la classe std::string
			str[j] = std::toupper(str[j]); // on modifie chaque char
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
