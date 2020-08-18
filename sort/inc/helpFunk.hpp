#ifndef FUNK
#define FUNK

#include <iostream>
#include <string>

#include "line.hpp"

enum Property
{
    NUMERAL,
    LITERAL,
    ROMAN,
    Def
};

/**
 *	Overloaded extraction >> operator to read content to the contact class.
 *
 *	@param other The class to read from.
 */
std::istream &operator>>(std::istream &in, Line &other);

/**
 *	Overloaded insertion << operator to write content of a contact class.
 *
 *	@param other The class to write to.
 */
std::ostream &operator<<(std::ostream &out, const Line &other);

/**
 *	Prints out helptext of availble switches
 *
 */
void help();

/**
 *	Prints out vesion number
 *
 */
void version();

#endif // !FUNK
