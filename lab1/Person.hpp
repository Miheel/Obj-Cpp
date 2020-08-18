#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>

struct address
{
	std::string street{};
	int zip{};
	std::string city{};
};
struct person
{
	std::string name{};
	std::string id{};
	address location;
};

enum SEARCHF { NAME, CITY }; //determine whether find names or find city is to be used

typedef std::vector<person> person_vec;
typedef std::vector<person>::iterator person_vec_it;
typedef std::pair<size_t, person_vec> found_pair;

/**
*	Read from file <filename> with the format
*	Name \ n
*	ID \ n
*	Street data , 5 digit zip [2 SPACE ] city \ n
*	@returns vector<person>. If file is not found, it returns an empty vector .
*/
person_vec read_file(std::string filename);

/**
*	Look in vector for names containing the substring name_part.
*	The search is case insensitive .
*	@returns the number of occurences name_part is found .
*/
size_t find_in_names(person_vec persons, std::string name_part);

/**
*	Look in vector for persons living in a particular city .
*	Exact matches only .
*	The search is case insensitive .
*	@returns a vector containg the matched persons .
*/
person_vec find_person_from_city(person_vec haystack, std::string city);

found_pair search_in_list(person_vec persons, std::string term, const SEARCHF &filter);

std::istream &operator>>(std::istream &in, person &p);

std::string toUpper(std::string other);

#endif // !PERSON_HPP
