#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Person.hpp"

#if defined _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void print(person_vec vec);

int main()
{
	size_t nrOfNames = 0;
	std::string sTerm, menuChoice;
	person_vec Persons = read_file("names.txt"), nrOfCities;

	while (menuChoice != "3")
	{
		system(CLEAR);
		std::cout << "1 - Sök del av personnamn.\n2 - Sök städer.\n3 - Avsluta.\n:";

		std::getline(std::cin, menuChoice);

		if (menuChoice.size() != 1 || !isdigit(menuChoice[0])) //Cheack so it sthe correct type of input
			menuChoice = "err";

		switch (menuChoice.front()) {

		case '1': //Sök personnamn
			system(CLEAR);

			std::cout << "Type a name to search for: ";
			std::getline(std::cin, sTerm);
			nrOfNames = find_in_names(Persons, sTerm);
			std::cout << "Nr of persons that matched the search term: " << nrOfNames << "\n";
			
			std::cin.get();
			break;
		case '2': //Sök städer
			system(CLEAR);
			
			std::cout << "Type a cityname to search for: ";
			std::getline(std::cin, sTerm);
			print(find_person_from_city(Persons, sTerm));
			
			std::cin.get();
			break;
		case '3': //Avsluta
			std::cout << "Quiting program\n";
			break;
		default:
			std::cout << "Wrong input try again\n";
		}
	}
	return 0;
}

void print(person_vec vec)
{
	person_vec_it it = vec.begin();

	if (!vec.empty())
	{	
		std::cout << "Cities that matched the search term\n";
		for (; it != vec.end(); it++)
		{
			std::cout << "Name: " << it->name << " City: " << it->location.city << std::endl;
		}
	}
	else
	{
		std::cout << "No matches was found\n";
	}
}
