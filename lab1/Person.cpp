#include "Person.hpp"

person_vec read_file(std::string filename)
{
	std::ifstream inFile(filename);
	person pers;
	person_vec persVec;

	if (inFile.is_open())
	{
		while (inFile >> pers)
		{
			persVec.push_back(pers);
		}
	}
	else
	{
		std::cout << "Could not open file" << std::endl;
		return persVec;
	}

	return persVec;
}

size_t find_in_names(person_vec persons, std::string name_part)
{
	//std::vector<person>::iterator it;
	//size_t NrOfNames = 0;
	//name_part = toUpper(name_part);
	//for (it = persons.begin(); it != persons.end(); it++)
	//{
	//	if (toUpper(it->name).find(name_part) != std::string::npos)
	//	{
	//		NrOfNames++;
	//	}
	//}
	//return NrOfNames;
	return search_in_list(persons, name_part, SEARCHF::NAME).first;
}

person_vec find_person_from_city(person_vec haystack, std::string city)
{
	//std::vector<person>::iterator it;
	//std::vector<person> foundCity;
	//city = toUpper(city);
	//for (it = haystack.begin(); it != haystack.end(); it++)
	//{
	//	if (toUpper(it->location.city) == city)
	//	{
	//		foundCity.push_back(*it);
	//	}
	//}
	//return foundCity;
	return search_in_list(haystack, city, SEARCHF::CITY).second;
}

found_pair search_in_list(person_vec persons, std::string term, const SEARCHF &filter)
{
	person_vec_it it;
	person_vec foundCity;
	size_t NrOfNames = 0;

	term = toUpper(term);

	for (it = persons.begin(); it != persons.end(); it++)
	{
		if ((toUpper(it->location.city) == term) && (filter == SEARCHF::CITY))
		{
			foundCity.push_back(*it);
		}

		if ((toUpper(it->name).find(term) != std::string::npos) && (filter == SEARCHF::NAME))
		{
			NrOfNames++;
		}
	}

	return std::make_pair(NrOfNames, foundCity);
}

std::istream & operator>>(std::istream & in, person & p)
{
	std::string zipBeg = "0", zipEnd = "0", cityEnd;

	std::getline(in, p.name);
	std::getline(in, p.id);
	std::getline(in, p.location.street, ',');

	in.ignore(); //Ignore the whitespace

	std::getline(in, zipBeg, ' '); //Read the first part of the zip code
	std::getline(in, zipEnd, ' '); //Read the second part of the zip code
	p.location.zip = stoi(zipBeg + zipEnd); //concatenate both parts and make it an int
	
	in.ignore(); //Ignore the whitespace

	std::getline(in, p.location.city, ' ');

	while (in.peek() != ' ' && in.peek() != EOF) //Peek the next char to see if it's a whitespace or EOF
	{											 //if not read the next part of the city name
		std::getline(in, cityEnd, ' '); 
		p.location.city += ' ' + cityEnd;
	}
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard all chars after city name

	return in;
}

std::string toUpper(std::string other)
{	
	static const std::vector<std::string> sweChar{"å", "Å", "ä", "Ä", "ö", "Ö"};
	size_t pos = 0;

	std::transform(other.begin(), other.end(), other.begin(), ::toupper);

	while (other.find(sweChar[0]) != std::string::npos
		|| other.find(sweChar[2]) != std::string::npos
		|| other.find(sweChar[4]) != std::string::npos)
	{
		if ((pos = other.find(sweChar[0])) != std::string::npos)
			other.replace(pos, sweChar[0].size(), sweChar[1]);

		if ((pos = other.find(sweChar[2])) != std::string::npos)
			other.replace(pos, sweChar[2].size(), sweChar[3]);

		if ((pos = other.find(sweChar[4])) != std::string::npos)
			other.replace(pos, sweChar[4].size(), sweChar[5]);
	}

	return other;
}
