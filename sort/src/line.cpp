#include "line.hpp"

void Line::setNumeral(std::string numeral)
{
	this->numeral = numeral;
}

void Line::setLiteral(std::string literal)
{
	this->literal = literal;
}

void Line::setRoman(std::string roman)
{
	this->roman = roman;
}

std::string Line::getNumeral() const
{
	return this->numeral;
}

std::string Line::getLiteral() const
{
	return this->literal;
}

std::string Line::getRoman() const
{
	return this->roman;
}

std::string Line::toString() const
{
	return this->getNumeral() + " " + this->getLiteral() + " " + this->getRoman();
}
