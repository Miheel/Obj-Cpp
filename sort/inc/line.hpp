#ifndef LINE_HPP
#define LINE_HPP

#include <string>

/**
 *	A class to represent a line from a file or standard in.
 */
class Line
{
public:
	void setNumeral(std::string numeral);
	void setLiteral(std::string literal);
	void setRoman(std::string roman);

	std::string getNumeral() const;
	std::string getLiteral() const;
	std::string getRoman() const;

	std::string toString() const;

private:
	std::string numeral;
	std::string literal;
	std::string roman;
};

#endif // !LINE_HPP
